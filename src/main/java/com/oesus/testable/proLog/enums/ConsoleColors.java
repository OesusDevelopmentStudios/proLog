package com.oesus.testable.proLog.enums;

public enum ConsoleColors
{
    RED("\033[0;31m"),
    YELLOW("\033[0;33m"),
    RESET("\033[0m");

    public final String color_;

    private ConsoleColors(String color)
    {
        color_ = color;
    }
}
