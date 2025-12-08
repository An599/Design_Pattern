#include "Command.h"

int main() {
    Editor editor("Hello");

    CopyCommand copyCmd(&editor);
    CutCommand cutCmd(&editor);
    PasteCommand pasteCmd(&editor);
    UndoCommand undoCmd(&editor);
    Button copyButton;
    Button cutButton;
    Button pasteButton;
    Button undoButton;

    copyButton.setCommand(&copyCmd);
    cutButton.setCommand(&cutCmd);
    pasteButton.setCommand(&pasteCmd);
    undoButton.setCommand(&undoCmd);
    ShortcutHandler shortcuts;
    shortcuts.onKeyPress("Ctrl+C", &copyCmd);
    shortcuts.onKeyPress("Ctrl+X", &cutCmd);
    shortcuts.onKeyPress("Ctrl+V", &pasteCmd);
    shortcuts.onKeyPress("Ctrl+Z", &undoCmd);

    std::cout << "BUTTON CLICKS \n";
    copyButton.click();
    cutButton.click();
    pasteButton.click();
    undoButton.click();

    std::cout << "\nSHORTCUT PRESSES \n";
    shortcuts.pressKey("Ctrl+C");
    shortcuts.pressKey("Ctrl+X");
    shortcuts.pressKey("Ctrl+V");
    shortcuts.pressKey("Ctrl+Z");

    std::cout << "\nNON-REGISTERED SHORTCUT\n";
    shortcuts.pressKey("Ctrl+Q");

    return 0;
}
