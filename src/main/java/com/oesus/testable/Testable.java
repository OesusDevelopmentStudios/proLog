package com.oesus.testable;

import com.oesus.testable.proLog.ProLog;

import com.oesus.testable.proLog.enums.LogLevel;


public class Testable
{
    private ProLog LOG = new ProLog("Testable", LogLevel.TOBOTH);


    public static void main(String[] args) { new Testable(); }
    public Testable() 
    {
        //LOG.build(LogLevel.ONLYTOCMD, "dummy");
        LOG.info("Starting application");
        run();
    }


    private void run()
    {
        LOG.info(" ProLog basic test");
    }
}
