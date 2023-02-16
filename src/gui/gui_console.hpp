#pragma once

#include "gui_element_types.hpp"

namespace ui {

class console_edit : public edit_box_element_base {
public:
	virtual void edit_box_enter(sys::state& state, std::string_view s) noexcept;
};

class console_list : public listbox_element_base {
public:
};

class console_window : public window_element_base {
public:
	std::unique_ptr<element_base> make_child(sys::state& state, std::string_view name, dcon::gui_def_id id) noexcept override {
		if(name == "console_list") {
			return make_element_by_type<console_list>(state, id);
		} else if(name == "console_edit") {
			return make_element_by_type<console_edit>(state, id);
		} else {
			return nullptr;
		}
	}

	static void show_toggle(sys::state& state);
};
}