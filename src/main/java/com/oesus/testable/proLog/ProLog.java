package com.oesus.testable.proLog;

import java.time.format.DateTimeFormatter;

import java.time.LocalDateTime;    

import com.oesus.testable.proLog.enums.LogLevel;
import com.oesus.testable.proLog.enums.ConsoleColors;

import com.oesus.testable.proLog.Logger.Log;
//import com.oesus.testable.proLog.Logger.LoggerService;


public class ProLog
{
    private String className_;
    private LogLevel logLevel_;
    // private LoggerServices loggerServices_;
    private DateTimeFormatter dateTimeFormatter_;


    public ProLog(String className/*, LoggerServices loggerServices*/)
    {
        this(className/*, loggerServices*/, LogLevel.TOBOTH);
    }

    public ProLog(String className/*, LoggerServices loggerServices*/, LogLevel logLevel)
    {
        className_ = className;
        //loggerServices_ = loggerServices;
        logLevel_ = logLevel;
        dateTimeFormatter_ = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss:SSS");  
    }


    public void info(String message)
    {   
        Log log =  new Log("[INFO]", getCurrentTime(), className_, getCallerName(), message);
        System.out.print(log.toString());
    }

    public void warning(String message)
    {
        Log log =  new Log("[WARN]", getCurrentTime(), className_, getCallerName(), message, ConsoleColors.YELLOW);
        System.out.print(log.toString());
    }

    public void error(String message)
    {
        Log log =  new Log("[ERROR]", getCurrentTime(), className_, getCallerName(), message, ConsoleColors.RED);
        System.out.print(log.toString());
    }

    public void trace(String message, String stackTrace)
    {}


    private String getCallerName()
    {
        try
        {
            StackTraceElement[] stacktrace = Thread.currentThread().getStackTrace();
            StackTraceElement element = stacktrace[3];
            String methodName = element.getMethodName();

            return methodName;
        }
        catch (Exception error)
        {
            return "unknown";
        }
    }

    private String getCurrentTime()
    {
        LocalDateTime now = LocalDateTime.now();

        return dateTimeFormatter_.format(now);
    }
}
