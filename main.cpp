#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFont>
#include <QResizeEvent>

class TicTacToe : public QWidget {
public:
    TicTacToe(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onButtonClicked();

private:
    QPushButton *buttons[3][3];
    bool playerTurn = true;

    bool checkWin();
    void resetGame();
    bool isBoardFull();
    void updateButtonFonts();
};

TicTacToe::TicTacToe(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Tic Tac Toe");
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(1);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = new QPushButton();
            button->setFont(QFont("Arial", 24));
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            connect(button, &QPushButton::clicked, this, &TicTacToe::onButtonClicked);
            gridLayout->addWidget(button, row, col);
            buttons[row][col] = button;
        }
    }

    setLayout(gridLayout);
}

void TicTacToe::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    updateButtonFonts();
}

void TicTacToe::updateButtonFonts() {
    int side = qMin(width(), height()) / 10;
    QFont font("Arial", side, QFont::Bold);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            buttons[row][col]->setFont(font);
        }
    }
}

bool TicTacToe::isBoardFull() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (buttons[row][col]->text().isEmpty()) {
                return false;
            }
        }
    }
    return true;
}


void TicTacToe::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button && button->text().isEmpty()) {
        button->setText(playerTurn ? "X" : "O");
        playerTurn = !playerTurn;

        if (checkWin()) {
            QMessageBox::information(this, "Game Over", QString("%1 Wins!").arg(!playerTurn ? "X" : "O"));
            resetGame();
        } else if (isBoardFull()) {
            QMessageBox::information(this, "Game Over", "It's a tie!");
            resetGame();
        }
    }
}


bool TicTacToe::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (!buttons[i][0]->text().isEmpty() &&
            buttons[i][0]->text() == buttons[i][1]->text() &&
            buttons[i][1]->text() == buttons[i][2]->text()) {
            return true;
        }

        if (!buttons[0][i]->text().isEmpty() &&
            buttons[0][i]->text() == buttons[1][i]->text() &&
            buttons[1][i]->text() == buttons[2][i]->text()) {
            return true;
        }
    }

    if (!buttons[0][0]->text().isEmpty() &&
        buttons[0][0]->text() == buttons[1][1]->text() &&
        buttons[1][1]->text() == buttons[2][2]->text()) {
        return true;
    }

    if (!buttons[0][2]->text().isEmpty() &&
        buttons[0][2]->text() == buttons[1][1]->text() &&
        buttons[1][1]->text() == buttons[2][0]->text()) {
        return true;
    }

    return false;
}

void TicTacToe::resetGame() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            buttons[row][col]->setText("");
        }
    }
    playerTurn = true;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TicTacToe window;
    window.showMaximized();

    return app.exec();
}
