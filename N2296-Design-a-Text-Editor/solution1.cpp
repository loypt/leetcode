class TextEditor {
private:
    list<char> editor;
    list<char>::iterator cursor;

public:
    TextEditor() {
        cursor = editor.end();
    }

    void addText(string text) {
        for (char c : text) {
            editor.insert(cursor, c);
        }
    }

    int deleteText(int k) {
        int count = 0;
        for (; k > 0 && cursor != editor.begin(); k--) {
            editor.erase(prev(cursor));
            count++;
        }
        return count;
    }

    string cursorLeft(int k) {
        while (k > 0 && cursor != editor.begin()) {
            k--;
            cursor = prev(cursor);
        }
        auto head = cursor;
        for (int i = 0; i < 10 && head != editor.begin(); i++) {
            head = prev(head);
        }
        return string(head, cursor);
    }

    string cursorRight(int k) {
        while (k > 0 && cursor != editor.end()) {
            k--;
            cursor = next(cursor);
        }
        auto head = cursor;
        for (int i = 0; i < 10 && head != editor.begin(); i++) {
            head = prev(head);
        }
        return string(head, cursor);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
