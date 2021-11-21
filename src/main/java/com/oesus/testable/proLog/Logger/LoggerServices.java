package com.oesus.testable.proLog.Logger;

import java.util.Stack;

import com.oesus.testable.proLog.ProLog;

public class LoggerServices extends Thread
{
    private boolean online_ = true;
    private Stack<Log> messages_;
    //private ProLog LOG = new ProLog("LoggerServices", this);

    @Override
    public void run()
    {
        try
        {
            while(online_ || !messages_.empty())
            {
                if (messages_.empty())
                {
                    Thread.sleep(1000);
                }
                else
                {
                    write();
                }
            }
            houseKeeping();
        }
        catch (InterruptedException exception)
        {
            online_ = false;
            //LOG.error("LoggerServcies thread was interrupted");
        }
    }

    public void end()
    {
        online_ = false;
    }

    public void log(Log log)
    {
        if (online_)
        {
            messages_.push(log);
        }
    }

    private void write()
    {

    }

    private void houseKeeping()
    {

    }
}
