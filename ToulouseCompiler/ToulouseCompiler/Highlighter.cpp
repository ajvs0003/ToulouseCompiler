#include "Highlighter.h"



Highlighter::Highlighter(QTextDocument* parent)
	: QSyntaxHighlighter(parent)
{
	HighlightingRule rule;

	keywordFormat.setForeground(Qt::darkBlue);
	keywordFormat.setFontWeight(QFont::Bold);

	reservedKeywordFormat.setForeground(Qt::darkMagenta);
	reservedKeywordFormat.setFontWeight(QFont::Bold);
	const QString reservedKeywordPatterns[] = {
		QStringLiteral("\\blayout\\b"),QStringLiteral("\\bgl_Position\\b"),QStringLiteral("\\bgl_FrontFacing\\b"),
		QStringLiteral("\\bnormalize\\b"),QStringLiteral("\\bnormalize\\b"),QStringLiteral("\\bgl_PointSize\\b"),
		QStringLiteral("\\bgl_Vertex\\b"),QStringLiteral("\\bgl_FragCoord\\b"),QStringLiteral("\\bgl_FragColor\\b"),
		QStringLiteral("\\bradians\\b"),QStringLiteral("\\bdegrees\\b"),QStringLiteral("\\bsin\\b"),
		QStringLiteral("\\bcos\\b"),QStringLiteral("\\btan\\b"),QStringLiteral("\\basin\\b"),
		QStringLiteral("\\bacos\\b"),QStringLiteral("\\bpow\\b"),QStringLiteral("\\bpow\\b"),
		QStringLiteral("\\blog\\b"),QStringLiteral("\\bexp2\\b"),QStringLiteral("\\blog2\\b"),
		QStringLiteral("\\bsqrt\\b"),QStringLiteral("\\binversesqrt\\b"),QStringLiteral("\\babs\\b"),
		QStringLiteral("\\bsign\\b"),QStringLiteral("\\bfloor\\b"),QStringLiteral("\\bmod\\b"),
		QStringLiteral("\\bmin\\b"),QStringLiteral("\\bmax\\b"),QStringLiteral("\\bclamp\\b"),
		QStringLiteral("\\bmix\\b"),QStringLiteral("\\bstep\\b"),QStringLiteral("\\bsmoothstep\\b"),
		QStringLiteral("\\blength\\b"),QStringLiteral("\\bdistance\\b"),QStringLiteral("\\bdot\\b"),
		QStringLiteral("\\bcross\\b"),QStringLiteral("\\bftransform\\b"),QStringLiteral("\\bfaceforward\\b"),
		QStringLiteral("\\blessThan\\b"),QStringLiteral("\\blessThanEqual\\b"),QStringLiteral("\\bgreaterThan\\b"),
		QStringLiteral("\\bgreaterThanEqual\\b"),QStringLiteral("\\bequal\\b"),QStringLiteral("\\bnotEqual\\b"),
		QStringLiteral("\\bany\\b"),QStringLiteral("\\ball\\b"),QStringLiteral("\\bnot\\b"),
		QStringLiteral("\\bMatrixCompMult\\b"),QStringLiteral("\\btexture\\b"),QStringLiteral("\\bdiscard\\b"),
		QStringLiteral("\\bgl_PointCoord\\b"),QStringLiteral("\\breflect\\b")
	};

	for (const QString& pattern : reservedKeywordPatterns) {
		rule.pattern = QRegularExpression(pattern);
		rule.format = reservedKeywordFormat;
		//añade la regla al vector de reglas
		highlightingRules.append(rule);
	}

	const QString keywordPatterns[] = {
		QStringLiteral("\\buniform\\b"), QStringLiteral("\\blocation\\b"),QStringLiteral("\\bout\\b"),
		QStringLiteral("\\bin\\b"),QStringLiteral("\\breturn\\b"),QStringLiteral("\\bstruct\\b"),
		QStringLiteral("\\bvoid\\b"),QStringLiteral("\\bconst\\b"),QStringLiteral("\\binout\\b"),
		QStringLiteral("\\bif\\b"),QStringLiteral("\\belse\\b"),QStringLiteral("\\bfor\\b")
	};
	for (const QString& pattern : keywordPatterns) {
		rule.pattern = QRegularExpression(pattern);
		rule.format = keywordFormat;
		//añade la regla al vector de reglas
		highlightingRules.append(rule);
	}


	variableFormat.setForeground(Qt::darkGreen);
	variableFormat.setFontWeight(QFont::Bold);

	const QString variablePatterns[] = {
		QStringLiteral("\\bvec2\\b"),QStringLiteral("\\bvec3\\b"), QStringLiteral("\\bvec4\\b"),
		QStringLiteral("\\bfloat\\b"),QStringLiteral("\\buint\\b"), QStringLiteral("\\bint\\b"),
		QStringLiteral("\\bbool\\b"),QStringLiteral("\\bmat4\\b"),QStringLiteral("\\bmat3\\b"),
		QStringLiteral("\\bmat2\\b"),QStringLiteral("\\bsampler2D\\b"),QStringLiteral("\\bsampler1D\\b"),
		QStringLiteral("\\bsampler3D\\b"),QStringLiteral("\\bsamplerCube\\b"),QStringLiteral("\\bsampler1DShadow\\b"),
		QStringLiteral("\\bsampler2DShadow\\b")
	};
	for (const QString& pattern : variablePatterns) {
		rule.pattern = QRegularExpression(pattern);
		rule.format = variableFormat;
		//añade la regla al vector de reglas
		highlightingRules.append(rule);
	}


	classFormat.setFontWeight(QFont::Bold);
	classFormat.setForeground(Qt::darkCyan);
	rule.pattern = QRegularExpression("\\bQ[A-Za-z]+\\b");
	rule.format = classFormat;

	//añade la regla al vector de reglas
	highlightingRules.append(rule);

	singleLineCommentFormat.setForeground(Qt::darkGreen);
	rule.pattern = QRegularExpression("//[^\n]*");
	rule.format = singleLineCommentFormat;
	highlightingRules.append(rule);

	multiLineCommentFormat.setForeground(Qt::darkGreen);





	functionFormat.setFontItalic(true);
	functionFormat.setForeground(Qt::blue);
	rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
	rule.format = functionFormat;
	highlightingRules.append(rule);

	commentStartExpression = QRegularExpression("/\\*");
	commentEndExpression = QRegularExpression("\\*/");
}




void Highlighter::highlightBlock(const QString& text)
{
	foreach(const HighlightingRule & rule, highlightingRules) {
		QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
		while (matchIterator.hasNext()) {
			QRegularExpressionMatch match = matchIterator.next();
			setFormat(match.capturedStart(), match.capturedLength(), rule.format);
		}
	}

	setCurrentBlockState(0);



	int startIndex = 0;
	if (previousBlockState() != 1)
		startIndex = text.indexOf(commentStartExpression);


	while (startIndex >= 0) {

		QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
		int endIndex = match.capturedStart();
		int commentLength = 0;
		if (endIndex == -1) {
			setCurrentBlockState(1);
			commentLength = text.length() - startIndex;
		}
		else {
			commentLength = endIndex - startIndex
				+ match.capturedLength();
		}
		setFormat(startIndex, commentLength, multiLineCommentFormat);
		startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
	}
}
