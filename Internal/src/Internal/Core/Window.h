/*
    Author: Shaun Fulham
    Copyright: Internal Media Group
    Licence: IMG Public Licence
*/

#pragma once

#include <stdint.h>
#include "Module.h"

namespace Internal
{
    struct WindowData
    {
        const char* Title;
        uint32_t width, height;
        bool IsFocused;
    };

    // Base Window Class
    class Window : public Module
    {
    protected:
        Window(WindowData& data);
    public:
        virtual void setTitle(const char* title) = 0;
        const char* getTitle() const {return m_Data.Title;}

        virtual void setWidth(uint32_t width) = 0;
        virtual void setHeight(uint32_t height) = 0;
        uint32_t getWidth() {return m_Data.width;}
        uint32_t getHeight() {return m_Data.height;}

        bool getFocused() {return m_Data.IsFocused;}

        virtual void OnUpdate() = 0;
    protected:
        WindowData m_Data;
    };
}