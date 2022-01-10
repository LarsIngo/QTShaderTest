#include "UIManager.hpp"

int main(int argc, char *argv[])
{
    // Initialize app with content.
    QGuiApplication* app = SpellScaper::UIManager::Initialize(argc, argv);

    // Run app.
    return app->exec();
}
