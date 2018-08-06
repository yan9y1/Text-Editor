#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TextEdit.h"
#include <qplaintextedit.h>
#include <qfiledialog.h>
#include <qprinter.h>
#include <QCloseEvent>

class TextEdit : public QMainWindow
{
	Q_OBJECT

public:
	TextEdit(QWidget *parent = Q_NULLPTR);

private:
	Ui::TextEditClass ui;

	void createFileActions();
	void createEditActions();
	void createFormatActions();
	void createHelpActions();
	void createMenus();
	void createToolBar();

	/*void initialize();*/

	void closeEvent(QCloseEvent *event);

	QMenuBar *menuBar;

	QMenu *menuFile;
	QMenu *menuEdit;
	QMenu *menuFormat;
	QMenu *menuFont;
	QMenu *menuHelp;

	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *saveAsAct;
	QAction *printAct;
	QAction *printPreviewAct;
	QAction *exitAct;

	QAction *undoAct;
	QAction *redoAct;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;

	QAction *boldAct;
	QAction *italicAct;
	QAction *underlineAct;
	QAction *colorAct;

	QAction *aboutAct;
	QAction *aboutQtAct;

	QPlainTextEdit *textEdit;

	QString fName = "";

	bool isSaved = false;

private slots:

	void newFile();
	void openFile();
	void saveFile();
	void saveAsFile();
	void printFile();
	void printPreview();
	int exit();

	void undo();
	void redo();
	void cut();
	void copy();
	void paste();

	void bold();
	void italic();
	void underline();
	void color();

	void about();

	void printPreviewSlot(QPrinter *printer);
	void textChange();
	void selectChange();
};
