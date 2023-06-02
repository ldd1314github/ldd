#ifndef POINT_H
#define POINT_H

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QPointF>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QRectF>
#include <QInputDialog>
#include <QPolygonF>
#include <QPainterPath>

class MyWidget : public QWidget {
public:
    MyWidget(QWidget* parent = nullptr) : QWidget(parent) {
        // 创建按钮
        QPushButton* pointButton = new QPushButton("点", this);
        QPushButton* lineButton = new QPushButton("线", this);
        QPushButton* circleButton = new QPushButton("圆", this);
        QPushButton* polygonButton = new QPushButton("多边形", this);
        QPushButton* bufferButton = new QPushButton("缓冲区", this);
        connect(pointButton, &QPushButton::clicked, this, &MyWidget::handlePointButtonClick);
        connect(lineButton, &QPushButton::clicked, this, &MyWidget::handleLineButtonClick);
        connect(circleButton, &QPushButton::clicked, this, &MyWidget::handleCircleButtonClick);
        connect(polygonButton, &QPushButton::clicked, this, &MyWidget::handlePolygonButtonClick);
        connect(bufferButton, &QPushButton::clicked, this, &MyWidget::handleBufferButtonClick);

        // 创建水平布局
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->addWidget(pointButton);
        layout->addWidget(lineButton);
        layout->addWidget(circleButton);
        layout->addWidget(polygonButton);
        layout->addWidget(bufferButton);
        layout->addStretch(); // 可以根据需要调整按钮的位置

        setLayout(layout);

        // 设置窗口大小
        resize(400, 400);
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(Qt::black);

        // 绘制已经点击的点
        for (const QPointF& point : m_points) {
            painter.drawPoint(point);
        }

        // 绘制已经点击的线
        for (const QLineF& line : m_lines) {
            painter.drawLine(line);
        }

        // 绘制已经点击的圆
        for (const QRectF& circle : m_circles) {
            painter.drawEllipse(circle);
        }

        // 绘制已经点击的多边形
        for (const QPolygonF& polygon : m_polygonList) {
            painter.drawPolygon(polygon);
        }

        // 绘制缓冲区
        painter.setPen(Qt::red);
        painter.setBrush(Qt::NoBrush);
        for (const QPolygonF& buffer : m_buffers) {
            painter.drawPolygon(buffer);
        }
    }

    void mousePressEvent(QMouseEvent* event) override {
        // 在鼠标点击位置绘制点、线、圆或多边形
        if (event->button() == Qt::LeftButton) {
            QPointF point = event->localPos();
            if (m_drawMode == DrawMode::Point) {
                m_points.append(point);
            } else if (m_drawMode == DrawMode::Line) {
                if (m_lines.size() % 2 == 0) {
                    QLineF line(point, point);
                    m_lines.append(line);
                } else {
                    QLineF& line = m_lines.last();
                    line.setP2(point);
                }
            } else if (m_drawMode == DrawMode::Circle) {
                if (!m_drawingCircle) {
                    bool ok;
                    qreal radius = QInputDialog::getDouble(this, "输入半径", "请输入圆的半径:", 50, 0, 1000, 1, &ok);
                    if (!ok) return;
                    QRectF circleRect(point, QSizeF(2.0 * radius, 2.0 * radius));
                    m_circles.append(circleRect);
                    m_drawingCircle = true;
                } else {
                    m_drawingCircle = false;
                }
            } else if (m_drawMode == DrawMode::Polygon) {
                if (m_polygon.size() < 2) {
                    m_polygon.append(point);
                } else {
                    m_polygon.append(point);
                    if (isPolygonClosed()) {
                        m_polygonList.append(m_polygon);
                        m_polygon.clear();
                    }
                }
            }
            update();
        }
    }

private slots:
    void handlePointButtonClick() {
        m_drawMode = DrawMode::Point;
    }

    void handleLineButtonClick() {
        m_drawMode = DrawMode::Line;
    }

    void handleCircleButtonClick() {
        m_drawMode = DrawMode::Circle;
    }

    void handlePolygonButtonClick() {
        m_drawMode = DrawMode::Polygon;
    }

    void handleBufferButtonClick() {
        if (m_points.isEmpty()) return;
        bool ok;
        qreal width = QInputDialog::getDouble(this, "输入缓冲区宽度", "请输入缓冲区的宽度:", 10, 0, 1000, 1, &ok);
        if (!ok) return;

        QPolygonF buffer;
        for (const QPointF& point : m_points) {
            QPainterPath path;
            path.addEllipse(point, width, width);
            buffer += path.toFillPolygon();
        }
        m_buffers.append(buffer);
        update();
    }

private:
    enum class DrawMode {
        Point,
        Line,
        Circle,
        Polygon
    };

    bool isPolygonClosed() const {
        if (m_polygon.size() >= 3) {
            QPointF firstPoint = m_polygon.first();
            QPointF lastPoint = m_polygon.last();
            qreal distance = QLineF(firstPoint, lastPoint).length();
            return distance <= m_polygonCloseThreshold;
        }
        return false;
    }

    DrawMode m_drawMode = DrawMode::Point;
    QVector<QPointF> m_points;
    QVector<QLineF> m_lines;
    QVector<QRectF> m_circles;
    QVector<QPolygonF> m_polygonList;
    QVector<QPolygonF> m_buffers;
    QPolygonF m_polygon;
    qreal m_polygonCloseThreshold = 10.0;
    bool m_drawingCircle = false;
};

#endif // POINT_H
