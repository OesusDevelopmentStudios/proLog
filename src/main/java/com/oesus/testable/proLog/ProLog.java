package com.oesus.testable.proLog;

import java.time.format.DateTimeFormatter;

import java.time.LocalDateTime;    

import com.oesus.testable.proLog.enums.LogLevel;
import com.oesus.testable.proLog.enums.ConsoleColors;

import com.oesus.testable.proLog.Logger.Log;
import com.oesus.testable.proLog.Logger.LoggerServices;


public class ProLog
{
    private static LogLevel globalLogLevel_;
    private static LoggerServices loggerServices_;
    private static DateTimeFormatter dateFormatter_ = DateTimeFormatter.ofPattern("yyyy/MM/dd");
    private static DateTimeFormatter timeFormatter_ = DateTimeFormatter.ofPattern("HH:mm:ss:SSSS");

    private String className_;
    private LogLevel logLevel_;


    public ProLog(String className)
    {
        this(className, (globalLogLevel_ == null) ? LogLevel.ONLYTOCMD : globalLogLevel_);
    }

    public ProLog(String className, LogLevel logLevel)
    {
        className_ = className;
        logLevel_ = logLevel;
    }


    public void info(String message)
    {   
        Log log =  new Log("[INFO]", getCurrentDate(), getCurrentTime(), className_, getCallerName(), message);
        System.out.print(log.toString());
    }

    public void warning(String message)
    {
        Log log =  new Log("[WARN]", getCurrentDate(), getCurrentTime(), className_, getCallerName(), message, ConsoleColors.YELLOW);
        System.out.print(log.toString());
    }

    public void error(String message)
    {
        Log log =  new Log("[ERROR]", getCurrentDate(), getCurrentTime(), className_, getCallerName(), message, ConsoleColors.RED);
        System.out.print(log.toString());
    }


    // TODO: return false if LoggerService is already runnig or it couldn't be started for some reason
    public boolean build(LogLevel globalLogLevel, String logPath)
    {
        globalLogLevel_ = globalLogLevel;

        return true;
    }


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

    private String getCurrentDate()
    {
        LocalDateTime now = LocalDateTime.now();

        return dateFormatter_.format(now);
    }

    private String getCurrentTime()
    {
        LocalDateTime now = LocalDateTime.now();

        return timeFormatter_.format(now);
    }
}
