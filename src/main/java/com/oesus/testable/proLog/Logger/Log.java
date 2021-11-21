package com.oesus.testable.proLog.Logger;

import com.oesus.testable.proLog.enums.ConsoleColors;

public class Log
{
    private String level_;
    private String timeStamp_;
    private String className_;
    private String caller_;
    private String message_;
    private ConsoleColors color_;


    public Log(String level, String timeStamp, String className, String caller, String message)
    {
        this(level, timeStamp, className, caller, message, ConsoleColors.RESET);
    }

    public Log(String level, String timeStamp, String className, String caller, String message, ConsoleColors color)
    {
        level_ = level;
        timeStamp_ = timeStamp;
        className_ = className;
        caller_ = caller;
        message_ = message;
        color_ = color;
    }

    public String toString()
    {
        return color_.color_ + 
            level_ + " " + timeStamp_ + " > " + className_ + ": " + caller_ + "(): " + message_ + "\n" +
            ConsoleColors.RESET.color_;
    }
}
