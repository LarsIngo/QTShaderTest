#include "UIManager.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication* app = SpellScaper::UIManager::Initialize(argc, argv);

    return app->exec();
}
