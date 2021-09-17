#include <gtkmm.h>

class Window : public Gtk::Window {
    public:
        Gtk::VBox vbox;
        Gtk::Entry first_entry;
        Gtk::Entry last_entry;
        Gtk::Label first_label;
        Gtk::Label last_label;
        Gtk::Label combined_name;
        Gtk::Button button;

        Window() {
            vbox.pack_start(first_label);
            vbox.pack_start(first_entry);
            vbox.pack_start(last_label);
            vbox.pack_start(last_entry);
            vbox.pack_start(button);
            vbox.pack_start(combined_name);

            add(vbox);
            show_all();

            first_label.set_text("Enter first name:");
            last_label.set_text("Enter last name:");
            button.set_label("Combine names");
            button.set_sensitive(false);

            first_entry.signal_changed().connect([this]() {
                check_entries();
            });

            first_entry.signal_activate().connect([this]() {
                if(first_entry.get_text() != "" && last_entry.get_text() != "")
                    set_combined_name(); 
            });

            last_entry.signal_changed().connect([this]() {
                check_entries();
            });

            last_entry.signal_activate().connect([this]() {
                if(first_entry.get_text() != "" && last_entry.get_text() != "")
                    set_combined_name(); 
            });

            button.signal_clicked().connect([this]() {
                set_combined_name();
            });
        }

    private:
        void check_entries() {
            if(first_entry.get_text() != "" && last_entry.get_text() != "") {
                button.set_sensitive(true);
            } else {
                button.set_sensitive(false);
            }
        }

        void set_combined_name() {
            combined_name.set_text(first_entry.get_text() + " " + last_entry.get_text());
        }
};

int main() {
    Gtk::Main gtk_main;
    Window window;
    gtk_main.run(window);
}
