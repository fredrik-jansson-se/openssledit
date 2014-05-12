#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Menu {
    
    using Item = std::pair<
                                std::string,
                                std::function<void()>
                              >;

    Menu(std::string title) : title(std::move(title)) {}
    Menu(std::string title, std::initializer_list<Item> items)
        : items(std::move(items))
        , title(std::move(title))
            {}

    void operator()();

private:
    const std::vector<Item> items;
    const std::string title;
};
