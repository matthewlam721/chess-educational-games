/**
 * @file celebration.h
 * @author teamname: The QT's
 *
 * @brief
 * CS 3505
 * Assignment Name: A9-An-Educational-App
 *
 * The celebration class is reponsible for the well done screen when the player complete a puzzle.
 *
 * @date 2023-12-08
 */
#ifndef CELEBRATION_H
#define CELEBRATION_H

#include <QWidget>
#include <QTimer>
#include <Box2D/Box2D.h>

class celebration : public QWidget {
    Q_OBJECT

public:
    explicit celebration(QWidget *parent = nullptr);
    ~celebration() override;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    /**
     * @brief A slot to update the physics world.
     */
    void updateWorld();

signals:
    /**
     * @brief Signal emitted when a ball goes out of bounds of the screen.
     * @param ball The ball that went out of bounds.
     */
    void ballOutOfBoundSignal(b2Body *ball);

private:
    b2World *world;
    QTimer *timer;
    const float32 scale = 30.0f; // The ball size on screen
    const float initialVelocityMagnitude = 10.0f; // The ball speed
    const int updateInterval = 16; // Timer interval in ms (about 60 FPS)
    std::vector<b2Body*> balls;
    QPixmap backgroundPixmap; // The background of the celebration screen.

    /**
     * @brief Creates a new ball in the physics simulation.
     * @return The body of the created ball.
     */
    b2Body* createBall();

    /**
     * @brief Refreshes the properties of a ball in the physics world.
     * @param ball The ball to be refreshed.
     */
    void refreshBall(b2Body *ball);

};


#endif // CELEBRATION_H
