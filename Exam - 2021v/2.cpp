#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

class Button {
public:
    string label;
    function<void()> on_click;
    Button(string label, function<void()> on_click) : label(move(label)), on_click(move(on_click)) {}
    virtual ~Button() = default;

    virtual void activate() = 0;
    virtual string get_string() const = 0;

    friend ostream &operator<<(ostream &out, const Button &button) {
        return out << button.get_string();
    }
};

class ToggleButton : public Button {
public:
    bool toggled;

    ToggleButton(string label, bool toggled, function<void()> on_click) :
            Button(move(label), move(on_click)), toggled(toggled) {}

    void activate() override {
        toggled = !toggled;
        on_click();
    }

    string get_value() const {
        if(toggled)
            return "toggled";
        else
            return "not toggled";
    }

    string get_string() const override {
        return "ToggleButton, label: " + label + ", value: " + get_value();
    }
};

class LinkButton : public Button {
public:
    string link;
    LinkButton(string label, string link, function<void()> on_click) :
        Button(move(label), move(on_click)), link(move(link)) {}

    void activate() override {
        on_click();
    }

    string get_string() const override {
        return "LinkButton, label: " + label + ", link: " + link;
    }
};

int main() {
    vector<unique_ptr<Button>> buttons;

    buttons.emplace_back(make_unique<ToggleButton>(
        "Toggle something",
        true,
        [] { cout << "Toggled something" << endl; }
    ));

    buttons.emplace_back(make_unique<LinkButton>(
        "Link to somewhere",
        "https://ntnu.no",
        [] { cout << "Opened link" << endl; }
    ));

    for (auto &button : buttons) {
        cout << *button << endl;
        button->activate();
        cout << *button << endl;
    }

    return 0;
}
