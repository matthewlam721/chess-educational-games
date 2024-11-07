/**
 * @file lesson.cpp
 * @author teamname: The QT's
 *
 * @brief
 * CS 3505
 * Assignment Name: A9-An-Educational-App
 *
 * The lesson class is reponsible for all lessons stuff in the application.
 *
 * @date 2023-12-08
 */
#include "lesson.h"

Lesson::Lesson(QWidget *parent)
    : QWidget{parent}
{

}

Lesson::Lesson(LessonType pt, QWidget *parent)
    : QWidget{parent}
{
    nextButton = new QPushButton(this);
    nextButton->setStyleSheet("QPushButton{background-color: brown;"
                              "border-width: 6px; border-radius: 20px;"
                              "border: 2px black;}"
                              "QPushButton::hover{background-color: rgb(50, 255, 50)}");
    nextButton->setGeometry(675,550,100,50);
    nextButton->setText("Next");
    nextButton->show();

    connect(nextButton,
            &QAbstractButton::clicked,
            this,
            &Lesson::nextClicked);

    lessonType = pt;

    if (lessonType == Lesson1) {
        setUpLesson1();
    }

    else if (lessonType == Lesson2) {
        setUpLesson2();
    }

    else if (lessonType == Lesson3) {
        setUpLesson3();
    }

    else if (lessonType == Lesson4) {
        setUpLesson4();
    }

    else if (lessonType == Lesson5) {
        setUpLesson5();
    }

    else if (lessonType == Lesson6) {
        setUpLesson6();
    }
}

void Lesson::setUpLesson1() {
    QLabel *title = new QLabel(this);
    title->setStyleSheet("QLabel { background-color: brown; }");
    setStyleSheet("font-weight: bold;");
    title->setGeometry(50,25,700,100);
    title->setText("DOUBLE ATTACK / FORK");
    title->setFont(QFont("Arial", 25));
    title->setAlignment(Qt::AlignCenter);
    title->show();

    QLabel *mainInfo = new QLabel(this);
    mainInfo->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    mainInfo->setGeometry(50,200,300,200);
    mainInfo->setWordWrap(true);
    mainInfo->setText("A double-attack, or fork, occurs when you move one piece to a position that attacks two of the opponents pieces.");
    mainInfo->setAlignment(Qt::AlignCenter);
    mainInfo->show();

    QLabel *imageToDisplay = new QLabel(this);
    imageToDisplay->setPixmap(QPixmap(":/examples/Images/doubleAttackEx.jpg"));
    imageToDisplay->setScaledContents(true);
    imageToDisplay->setStyleSheet("QLabel { background-color: white; }");
    imageToDisplay->setGeometry(420,150,300,300);
    imageToDisplay->show();

    QLabel *funFactOrTip = new QLabel(this);
    funFactOrTip->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    funFactOrTip->setGeometry(25,470,750,50);
    funFactOrTip->setWordWrap(true);
    funFactOrTip->setText("In the example above, the white knight forks black's king and rook. Also, black's pawn forks the white rooks.");
    funFactOrTip->setAlignment(Qt::AlignCenter);
    funFactOrTip->show();
}

void Lesson::setUpLesson2() {
    QLabel *title = new QLabel(this);
    title->setStyleSheet("QLabel { background-color: brown; }");
    setStyleSheet("font-weight: bold;");
    title->setGeometry(50,25,700,100);
    title->setText("PINNED QUEEN");
    title->setFont(QFont("Arial", 25));
    title->setAlignment(Qt::AlignCenter);
    title->show();

    QLabel *mainInfo = new QLabel(this);
    mainInfo->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    mainInfo->setGeometry(50,200,300,200);
    mainInfo->setWordWrap(true);
    mainInfo->setText("A pin is a tactic in which a defending piece cannot move out of an attacking piece's line of attack without exposing a more valuable defending piece. Note that a queen can only ever be partially pinned, as it can move in any linear direction to escape.");
    mainInfo->setAlignment(Qt::AlignCenter);
    mainInfo->show();

    QLabel *imageToDisplay = new QLabel(this);
    imageToDisplay->setPixmap(QPixmap(":/examples/Images/pinnedQueenEx.jpg"));
    imageToDisplay->setScaledContents(true);
    imageToDisplay->setStyleSheet("QLabel { background-color: white; }");
    imageToDisplay->setGeometry(420,150,300,300);
    imageToDisplay->show();

    QLabel *funFactOrTip = new QLabel(this);
    funFactOrTip->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    funFactOrTip->setGeometry(25,470,750,50);
    funFactOrTip->setWordWrap(true);
    funFactOrTip->setText("In the example above, the black queen is pinned to the black king by the white rook, so the queen cannot move.");
    funFactOrTip->setAlignment(Qt::AlignCenter);
    funFactOrTip->show();
}

void Lesson::setUpLesson3() {
    QLabel *title = new QLabel(this);
    title->setStyleSheet("QLabel { background-color: brown; }");
    setStyleSheet("font-weight: bold;");
    title->setGeometry(50,25,700,100);
    title->setText("SMOTHERED MATE");
    title->setFont(QFont("Arial", 25));
    title->setAlignment(Qt::AlignCenter);
    title->show();

    QLabel *mainInfo = new QLabel(this);
    mainInfo->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    mainInfo->setGeometry(50,200,300,200);
    mainInfo->setWordWrap(true);
    mainInfo->setText("A smothered mate is a checkmate involving the knight. It occurs when the king is surrounded and the knight can jump over the surrounding pieces.");
    mainInfo->setAlignment(Qt::AlignCenter);
    mainInfo->show();

    QLabel *imageToDisplay = new QLabel(this);
    imageToDisplay->setPixmap(QPixmap(":/examples/Images/smotheredMateEx.jpg"));
    imageToDisplay->setScaledContents(true);
    imageToDisplay->setStyleSheet("QLabel { background-color: white; }");
    imageToDisplay->setGeometry(420,150,300,300);
    imageToDisplay->show();

    QLabel *funFactOrTip = new QLabel(this);
    funFactOrTip->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    funFactOrTip->setGeometry(25,470,750,50);
    funFactOrTip->setWordWrap(true);
    funFactOrTip->setText("In the example above, the black king is surrounded by its own pieces and thus the white knight has put the king in check.");
    funFactOrTip->setAlignment(Qt::AlignCenter);
    funFactOrTip->show();
}

void Lesson::setUpLesson4() {
    QLabel *title = new QLabel(this);
    title->setStyleSheet("QLabel { background-color: brown; }");
    setStyleSheet("font-weight: bold;");
    title->setGeometry(50,25,700,100);
    title->setText("OVERLOADING");
    title->setFont(QFont("Arial", 25));
    title->setAlignment(Qt::AlignCenter);
    title->show();

    QLabel *mainInfo = new QLabel(this);
    mainInfo->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    mainInfo->setGeometry(50,200,300,200);
    mainInfo->setWordWrap(true);
    mainInfo->setText("Overloading is a chess tactic in which a defensive piece is given an additional defensive assignment which it cannot complete without abandoning its original defensive assignment.");
    mainInfo->setAlignment(Qt::AlignCenter);
    mainInfo->show();

    QLabel *imageToDisplay = new QLabel(this);
    imageToDisplay->setPixmap(QPixmap(":/examples/Images/overloadingEx.jpg"));
    imageToDisplay->setScaledContents(true);
    imageToDisplay->setStyleSheet("QLabel { background-color: white; }");
    imageToDisplay->setGeometry(420,150,300,300);
    imageToDisplay->show();

    QLabel *funFactOrTip = new QLabel(this);
    funFactOrTip->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    funFactOrTip->setGeometry(25,470,750,50);
    funFactOrTip->setWordWrap(true);
    funFactOrTip->setText("In the example above, the white rook on f1 is preventing the black queen from giving checkmate by capturing the pawn on f3. Therefore black can win immediately with Re1, further pinning the white rook against the king and overloading the rook.");
    funFactOrTip->setAlignment(Qt::AlignCenter);
    funFactOrTip->show();
}

void Lesson::setUpLesson5() {
    QLabel *title = new QLabel(this);
    title->setStyleSheet("QLabel { background-color: brown; }");
    setStyleSheet("font-weight: bold;");
    title->setGeometry(50,25,700,100);
    title->setText("CONTROL THE KING");
    title->setFont(QFont("Arial", 25));
    title->setAlignment(Qt::AlignCenter);
    title->show();

    QLabel *mainInfo = new QLabel(this);
    mainInfo->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    mainInfo->setGeometry(50,200,300,200);
    mainInfo->setWordWrap(true);
    mainInfo->setText("In chess you win by putting the opponent's king in checkmate, however it is also very useful to force the opponent to move their king by putting them in check. This can help you to more easily get a checkmate as you move your pieces into position and your opponent can't do anything more than move their king. This can also allow you to move your pieces in such a way as to take out your opponent's more important pieces.");
    mainInfo->setAlignment(Qt::AlignCenter);
    mainInfo->show();

    QLabel *imageToDisplay = new QLabel(this);
    imageToDisplay->setPixmap(QPixmap(":/examples/Images/doubleAttackEx.jpg"));
    imageToDisplay->setScaledContents(true);
    imageToDisplay->setStyleSheet("QLabel { background-color: white; }");
    imageToDisplay->setGeometry(420,150,300,300);
    imageToDisplay->show();

    QLabel *funFactOrTip = new QLabel(this);
    funFactOrTip->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    funFactOrTip->setGeometry(25,470,750,50);
    funFactOrTip->setWordWrap(true);
    funFactOrTip->setText("In the image above black's king must be moved due to being in check from white's knight, this allows white to take black's rook.");
    funFactOrTip->setAlignment(Qt::AlignCenter);
    funFactOrTip->show();
}

void Lesson::setUpLesson6() {
    QLabel *title = new QLabel(this);
    title->setStyleSheet("QLabel { background-color: brown; }");
    setStyleSheet("font-weight: bold;");
    title->setGeometry(50,25,700,100);
    title->setText("FORK and PINNING");
    title->setFont(QFont("Arial", 25));
    title->setAlignment(Qt::AlignCenter);
    title->show();

    QLabel *mainInfo = new QLabel(this);
    mainInfo->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    mainInfo->setGeometry(50,200,300,200);
    mainInfo->setWordWrap(true);
    mainInfo->setText("In chess being able to combine tactics will greatly increase your chance for success. In these lessons we have gone over a few tactics like double attack or fork and pinning. If you can combine those tactics it will allow you to much more easily control the board and your opponent.");
    mainInfo->setAlignment(Qt::AlignCenter);
    mainInfo->show();

    QLabel *imageToDisplay = new QLabel(this);
    imageToDisplay->setPixmap(QPixmap(":/examples/Images/overloadingEx.jpg"));
    imageToDisplay->setScaledContents(true);
    imageToDisplay->setStyleSheet("QLabel { background-color: white; }");
    imageToDisplay->setGeometry(420,150,300,300);
    imageToDisplay->show();

    QLabel *funFactOrTip = new QLabel(this);
    funFactOrTip->setStyleSheet("QLabel { background-color: rgb(175, 104, 46); }");
    funFactOrTip->setGeometry(25,470,750,50);
    funFactOrTip->setWordWrap(true);
    funFactOrTip->setText("If black moves their queen to e6 they will be double attacking white's rook and bishop. White will then feel pressured to save one of their pieces. Black can then move their queen to h3, pinning white's pawn. On black's next turn they would then be able to take white's pawn and checkmate the king.");
    funFactOrTip->setAlignment(Qt::AlignCenter);
    funFactOrTip->show();
}

void Lesson::nextClicked(){
    if (lessonType == Lesson1) {
        emit lessonFinished(1);
    }

    else if (lessonType == Lesson2) {
        emit lessonFinished(2);
    }

    else if (lessonType == Lesson3) {
        emit lessonFinished(3);
    }

    else if (lessonType == Lesson4) {
        emit lessonFinished(4);
    }

    else if (lessonType == Lesson5) {
        emit lessonFinished(5);
    }

    else if (lessonType == Lesson6) {
        emit lessonFinished(6);
    }
}
