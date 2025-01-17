#pragma once
#include "gui/l10n/l10n.h"
#include <fmt/core.h>
#include <utility>

namespace deluge::gui::menu_item {

// Mixin for a formatted title
class FormattedTitle {
public:
	FormattedTitle(l10n::String format_str) : format_str_(format_str) {}

	void format(int32_t arg) { title_ = fmt::vformat(l10n::getView(format_str_), fmt::make_format_args(arg)); }

	[[nodiscard]] std::string_view title() const { return title_; }

private:
	l10n::String format_str_;
	std::string title_;
};
} // namespace deluge::gui::menu_item
