#include <QApplication>
#include <QtNodes/GraphicsView>
#include <QtNodes/BasicGraphicsScene>
#include "GraphModel.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 1. Create the graph model
    GraphModel model;

    // 2. Create a scene that visualizes the model
    auto* scene = new QtNodes::BasicGraphicsScene(model);

    // 3. Create a view to display the scene
    QtNodes::GraphicsView view(scene);
    view.setWindowTitle("My First Node Graph");
    view.resize(800, 600);
    view.show();

    view.setContextMenuPolicy(Qt::ActionsContextMenu);

    QAction* createAction = new QAction("Create Node", &view);
    QObject::connect(createAction, &QAction::triggered, [&]() {
        // Get mouse position in scene coordinates
        QPointF pos = view.mapToScene(view.mapFromGlobal(QCursor::pos()));

        // Add node to model
        auto nodeId = model.addNode();
        model.setNodeData(nodeId, QtNodes::NodeRole::Position, pos);
    });

    view.addAction(createAction);

    return app.exec();
}