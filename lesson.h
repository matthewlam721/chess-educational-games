/**
 * @file lesson.h
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
#ifndef LESSON_H
#define LESSON_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Lesson : public QWidget
{
    Q_OBJECT

public:
    enum LessonType
    {
        Lesson1,
        Lesson2,
        Lesson3,
        Lesson4,
        Lesson5,
        Lesson6
    };

    explicit Lesson(QWidget *parent = nullptr);

    explicit Lesson(LessonType, QWidget *parent = nullptr);

    LessonType lessonType;

signals:
    /**
     * @brief Emit signal when a lesson is finished.
     * @param lessonIndex The index of the finished lesson.
     */
    void lessonFinished(int);

private:
    // Set up the specific lessons
    void setUpLesson1();
    void setUpLesson2();
    void setUpLesson3();
    void setUpLesson4();
    void setUpLesson5();
    void setUpLesson6();

    QPushButton *nextButton;

    /**
     * @brief Handler for the "Next" button click.
     */
    void nextClicked();
};


#endif // LESSON_H
