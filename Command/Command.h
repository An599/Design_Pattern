#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

class Editor {
private:
    std::string text;

public:
    Editor(const std::string& initial = "") : text(initial) {}

    void copy() { std::cout << "[Editor] Copy executed" << std::endl; }
    void cut() { std::cout << "[Editor] Cut executed" << std::endl; }
    void paste() { std::cout << "[Editor] Paste executed" << std::endl; }
    void undo() { std::cout << "[Editor] Undo executed" << std::endl; }
};

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

class CopyCommand : public ICommand {
    Editor* editor;
public:
    CopyCommand(Editor* e) : editor(e) {}
    void execute() override 
    { 
        editor->copy(); 
    }
};

class CutCommand : public ICommand {
    Editor* editor;
public:
    CutCommand(Editor* e) : editor(e) {}
    void execute() override 
    { 
        editor->cut(); 
    }
};

class PasteCommand : public ICommand {
    Editor* editor;
public:
    PasteCommand(Editor* e) : editor(e) {}
    void execute() override 
    { 
        editor->paste(); 
    }
};

class UndoCommand : public ICommand {
    Editor* editor;
public:
    UndoCommand(Editor* e) : editor(e) {}
    void execute() override 
    { 
        editor->undo(); 
    }
};


class Button {
private:
    ICommand* command = nullptr;

public:
    void setCommand(ICommand* c) { command = c; }
    void click() {
        if (command) command->execute();
    }
};

class ShortcutHandler {
private:
    std::unordered_map<std::string, ICommand*> shortcuts;

public:
    void onKeyPress(const std::string& key, ICommand* command) {
        shortcuts[key] = command;
    }

    void pressKey(const std::string& key) {
        if (shortcuts.count(key))
            shortcuts[key]->execute();
        else
            std::cout << "[Shortcut] No command for " << key << "\n";
    }
};
