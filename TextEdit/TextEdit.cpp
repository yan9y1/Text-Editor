#include "TextEdit.h"
#include "qdebug.h"
#include <fstream>
#include <qmessagebox.h>
#include <QTextDocumentWriter>
#include <qprintdialog.h>
#include <qprinter.h>
#include <qprintpreviewdialog.h>
#include <qcolordialog.h>

TextEdit::TextEdit(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	textEdit = new QPlainTextEdit;
	setCentralWidget(textEdit);
	/*initialize();*/
	/*connect(textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(cursorMove()));*/
	connect(textEdit, SIGNAL(textChanged()), this, SLOT(textChange()));
	connect(textEdit, SIGNAL(selectionChanged()), this, SLOT(selectChange()));
	menuBar = new QMenuBar;

	createFileActions();
	createEditActions();
	createFormatActions();
	createHelpActions();
	
	createMenus();
	createToolBar();

	setMenuBar(menuBar);
}

//void TextEdit::initialize() {
//	QTextCharFormat fmt; 
//	fmt.setFontPointSize(15);
//	fmt.setFontFamily("Times New Roman");
//	textEdit->mergeCurrentCharFormat(fmt);
//}

void TextEdit::createFileActions() {
	newAct = new QAction(QIcon("icons/new.png"),tr("&New"), this);
	newAct->setShortcut(QKeySequence(tr("Ctrl+N")));
	newAct->setToolTip("New");
	newAct->setStatusTip(tr("Create a new file"));
	connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

	openAct = new QAction(QIcon("icons/open.png"), tr("&Open"), this);
	openAct->setShortcut(QKeySequence(tr("Ctrl+O")));
	openAct->setToolTip("Open");
	openAct->setStatusTip(tr("Open a file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

	saveAct = new QAction(QIcon("icons/save.png"), tr("&Save"), this);
	saveAct->setShortcut(QKeySequence(tr("Ctrl+S")));
	saveAct->setToolTip("Save");
	saveAct->setStatusTip(tr("Save the file"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));

	saveAsAct = new QAction(tr("&Save As..."), this);
	saveAsAct->setShortcut(QKeySequence(tr("Ctrl+Shift+S")));
	saveAsAct->setToolTip("Save As...");
	saveAsAct->setStatusTip(tr("Save the file as..."));
	connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAsFile()));

	printAct = new QAction(QIcon("icons/print.png"), tr("&Print"), this);
	printAct->setShortcut(QKeySequence(tr("Ctrl+P")));
	printAct->setToolTip("Print");
	printAct->setStatusTip(tr("Print the file"));
	connect(printAct, SIGNAL(triggered()), this, SLOT(printFile()));

	printPreviewAct = new QAction(QIcon("icons/printPreview.png"), tr("&Print Preview"), this);
	printPreviewAct->setToolTip("Print Preview");
	printPreviewAct->setStatusTip(tr("Print preview"));
	connect(printPreviewAct, SIGNAL(triggered()), this, SLOT(printPreview()));

	exitAct = new QAction(QIcon("icons/exit.png"), tr("&Exit"), this);
	exitAct->setShortcut(QKeySequence(tr("Esc")));
	exitAct->setToolTip("Exit");
	exitAct->setStatusTip(tr("Exit"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(exit()));
}


void TextEdit::createEditActions() {
	undoAct = new QAction(QIcon("icons/undo.png"), tr("&Undo"), this);
	undoAct->setShortcut(QKeySequence(tr("Ctrl+Z")));
	undoAct->setToolTip("Undo");
	undoAct->setStatusTip(tr("Undo"));
	connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

	redoAct = new QAction(QIcon("icons/redo.png"), tr("&Redo"), this);
	redoAct->setShortcut(QKeySequence(tr("Ctrl+Y")));
	redoAct->setToolTip("Redo");
	redoAct->setStatusTip(tr("Redo"));
	connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

	cutAct = new QAction(QIcon("icons/cut.png"), tr("&Cut"), this);
	cutAct->setShortcut(QKeySequence(tr("Ctrl+X")));
	cutAct->setToolTip("Cut");
	cutAct->setStatusTip(tr("Cut"));
	connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));

	copyAct = new QAction(QIcon("icons/copy.png"), tr("&Copy"), this);
	copyAct->setShortcut(QKeySequence(tr("Ctrl+C")));
	copyAct->setToolTip("Copy");
	copyAct->setStatusTip(tr("Copy"));
	connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

	pasteAct = new QAction(QIcon("icons/paste.png"), tr("&Paste"), this);
	pasteAct->setShortcut(QKeySequence(tr("Ctrl+V")));
	pasteAct->setToolTip("Paste");
	pasteAct->setStatusTip(tr("Paste"));
	connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));
}

void TextEdit::createFormatActions() {
	boldAct = new QAction(QIcon("icons/bold.png"), tr("&Bold"), this);
	boldAct->setShortcut(QKeySequence(tr("Ctril+B")));
	boldAct->setToolTip("Bold");
	boldAct->setStatusTip(tr("Bold"));
	boldAct->setCheckable(true);
	connect(boldAct, SIGNAL(triggered()), this, SLOT(bold()));

	italicAct = new QAction(QIcon("icons/italic.png"), tr("&Italic"), this);
	italicAct->setShortcut(QKeySequence(tr("Ctril+I")));
	italicAct->setToolTip("Italic");
	italicAct->setStatusTip(tr("Italic"));
	italicAct->setCheckable(true);
	connect(italicAct, SIGNAL(triggered()), this, SLOT(italic()));

	underlineAct = new QAction(QIcon("icons/underline.png"), tr("&Underline"), this);
	underlineAct->setShortcut(QKeySequence(tr("Ctril+U")));
	underlineAct->setToolTip("Underline");
	underlineAct->setStatusTip(tr("Underline"));
	underlineAct->setCheckable(true);
	connect(underlineAct, SIGNAL(triggered()), this, SLOT(underline()));

	colorAct = new QAction(QIcon("icons/color.png"), tr("&Color"), this);
	colorAct->setToolTip("Color");
	colorAct->setStatusTip(tr("Color"));
	connect(colorAct, SIGNAL(triggered()), this, SLOT(color()));
}

void TextEdit::createHelpActions() {
	aboutAct = new QAction(tr("&About"), this);
	aboutAct->setToolTip("About");
	aboutAct->setStatusTip(tr("About"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAct = new QAction(QIcon("icons/aboutQt.png"), tr("&About Qt"), this);
	aboutQtAct->setToolTip("AboutQt");
	aboutQtAct->setStatusTip(tr("AboutQt"));
	connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void TextEdit::createMenus() {
	menuFile = menuBar->addMenu(tr("&File"));
	menuFile->addAction(newAct);
	menuFile->addAction(openAct);
	menuFile->addAction(saveAct);
	menuFile->addAction(saveAsAct);
	menuFile->addAction(printAct);
	menuFile->addAction(printPreviewAct);
	menuFile->addAction(exitAct);

	menuEdit = menuBar->addMenu(tr("&Edit"));
	menuEdit->addAction(undoAct);
	menuEdit->addAction(redoAct);
	menuEdit->addAction(cutAct);
	menuEdit->addAction(copyAct);
	menuEdit->addAction(pasteAct);

	menuFormat = menuBar->addMenu(tr("&Format"));
	menuFormat->addSeparator();
	menuFont = menuFormat->addMenu(tr("&Font"));
	menuFont->addAction(boldAct);
	menuFont->addAction(italicAct);
	menuFont->addAction(underlineAct);
	menuFormat->addAction(colorAct);

	menuHelp = menuBar->addMenu(tr("&Help"));
	menuHelp->addAction(aboutAct);
	menuHelp->addAction(aboutQtAct);
}

void TextEdit::createToolBar() {
	ui.mainToolBar->addAction(newAct);
	ui.mainToolBar->addAction(newAct);
	ui.mainToolBar->addAction(openAct);
	ui.mainToolBar->addAction(saveAct);
	ui.mainToolBar->addAction(printAct);

	QToolBar *editToolBar = addToolBar(tr("Edit"));
	editToolBar->addAction(undoAct);
	editToolBar->addAction(redoAct);
	editToolBar->addAction(cutAct);
	editToolBar->addAction(copyAct);
	editToolBar->addAction(pasteAct);

	QToolBar *formatToolBar = addToolBar(tr("Format"));
	formatToolBar->addAction(boldAct);
	formatToolBar->addAction(italicAct);
	formatToolBar->addAction(underlineAct);
	formatToolBar->addAction(colorAct);

}

void TextEdit::newFile() {
	if (!isSaved) {
		int signal = QMessageBox::warning(this, tr("Warning"), tr("Do you want to save the changes?"), QMessageBox::Save | QMessageBox::Discard, QMessageBox::Save);
		switch (signal) {
		case QMessageBox::Save:
			saveFile();
			break;
		case QMessageBox::Discard:
			textEdit->clear();
			break;
		}
	}
	else {
		textEdit->clear();
		fName = "";
	}
}

void TextEdit::openFile() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open"), QString(), tr("Text document (*.txt);;all files(*.*)"));
	if (fileName == "") return;
	QFile file(fileName);
	fName = fileName;
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox::warning(this, tr("Error"), tr("The file can't be opened"));
		return;
	}
	QTextStream in(&file);
	QString str = in.readAll();
	textEdit->setPlainText(str);
}

void TextEdit::saveFile() {
	if (fName != "") {
		QFile file(fName);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Error"), tr("The file can't be opened"));
			return;
		}
		QTextStream out(&file);
		QString str = textEdit->toPlainText();
		out << str;
	}
	else {
		saveAsFile();
	}
	isSaved = true;
}

void TextEdit::saveAsFile() {
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), QString(), tr("Text document (*.txt);;all files(*.*)"));
	QTextDocumentWriter writer(fileName);
	QString str = textEdit->toPlainText();
	QTextDocument file(str);
	bool success = writer.write(&file);
}

void TextEdit::printFile() {
	QPrinter printer(QPrinter::ScreenResolution);
	QPrintDialog *printDialog = new QPrintDialog(&printer, this);
	printDialog->exec();
}

void TextEdit::printPreview() {
	QPrinter printer(QPrinter::ScreenResolution);
	printer.setPageSize(QPrinter::Custom);
	printer.setPaperSize(QSizeF(textEdit->height(), textEdit->width()),QPrinter::Point);
	QPrintPreviewDialog preview(&printer,this);
	connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreviewSlot(QPrinter*)));
	preview.exec();
}

void TextEdit::printPreviewSlot(QPrinter* printer) {
	QTextDocument *textDoc = textEdit->document();
	textDoc->print(printer);
}

int TextEdit::exit() {
	if (!isSaved) {
		int signal = QMessageBox::warning(this, tr("Warning"), tr("Do you want to save the changes?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save);
		switch (signal) {
		case QMessageBox::Save:
			saveFile();
			break;
		case QMessageBox::Discard:
			return 0;
			QCoreApplication::exit(0);
		case QMessageBox::Cancel:
			return 0;
			break;
		}
		return 1;
	}
	else {
		QCoreApplication::exit(0);
	}
	return 0;
}

void TextEdit::undo() {
	textEdit->undo();
}

void TextEdit::redo() {
	textEdit->redo();
}

void TextEdit::cut() {
	textEdit->cut();
}

void TextEdit::copy() {
	textEdit->copy();
}

void TextEdit::paste() {
	textEdit->paste();
}

void TextEdit::bold() {
	QTextCharFormat fmt = textEdit->currentCharFormat();
	if (boldAct->isChecked()) {
		fmt.setFontWeight(QFont::Bold);
		textEdit->setCurrentCharFormat(fmt);
	}
	else {
		fmt.setFontWeight(QFont::Normal);
		textEdit->setCurrentCharFormat(fmt);
	}
}

void TextEdit::italic() {
	QTextCharFormat fmt = textEdit->currentCharFormat();
	if (italicAct->isChecked()) {
		fmt.setFontItalic(true);
		textEdit->setCurrentCharFormat(fmt);
	}
	else {
		fmt.setFontItalic(false);
		textEdit->setCurrentCharFormat(fmt);
	}
}

void TextEdit::underline() {
	QTextCharFormat fmt = textEdit->currentCharFormat();
	if (underlineAct->isChecked()) {
		fmt.setFontUnderline(true);
		textEdit->setCurrentCharFormat(fmt);
	}
	else {
		fmt.setFontUnderline(false);
		textEdit->setCurrentCharFormat(fmt);
	}
}

void TextEdit::color() {
	QColor color = QColorDialog::getColor();
	QTextCharFormat fmt = textEdit->currentCharFormat();
	fmt.setForeground(color);
	textEdit->setCurrentCharFormat(fmt);
}

void TextEdit::about() {
	QMessageBox::about(this, tr("About"), tr("This is a simple text editor. Powered by Yang Yi"));
}

void TextEdit::closeEvent(QCloseEvent *event) {
	int res = exit();
	if (res) event->ignore();
}

void TextEdit::textChange() {
	QString str = textEdit->toPlainText();
	isSaved = false;
}

void TextEdit::selectChange() {
	QTextCharFormat fmt = textEdit->currentCharFormat();
	int weight = fmt.fontWeight();
	bool italic = fmt.fontItalic();
	bool underline = fmt.fontUnderline();
	if (weight == 75) boldAct->setChecked(true);
	else boldAct->setChecked(false);
	if (italic) italicAct->setChecked(true);
	else italicAct->setChecked(false);
	if (underline) underlineAct->setChecked(true);
	else underlineAct->setChecked(false);
}