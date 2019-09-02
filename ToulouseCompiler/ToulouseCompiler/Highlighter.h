#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class Highlighter : public QSyntaxHighlighter
{
	Q_OBJECT

public:
	Highlighter(QTextDocument *parent = 0);

protected:
	void highlightBlock(const QString &text) override;

private:
	struct HighlightingRule
	{
		QRegularExpression pattern;
		QTextCharFormat format;
	};
	QVector<HighlightingRule> highlightingRules;

	QRegularExpression commentStartExpression;
	QRegularExpression commentEndExpression;

	QTextCharFormat keywordFormat;//formato para system varibles
	QTextCharFormat reservedKeywordFormat;//formato para system varibles
	QTextCharFormat variableFormat;//formato para las variables
	QTextCharFormat classFormat;// formato para la clase
	QTextCharFormat singleLineCommentFormat;//formato para coemntario de linea

	QTextCharFormat multiLineCommentFormat;//formato para comentario de varias lineas

	//QTextCharFormat quotationFormat; //formato para comillas 
	QTextCharFormat functionFormat;//formato de funcion
};

