package com.oesus.testable;

import com.oesus.testable.proLog.ProLog;

public class Testable
{
    private ProLog LOG;


    public static void main(String[] args) { new Testable(); }
    public Testable() 
    {
        run();
    }


    private void run()
    {
        System.out.print(" ProLog basic test");
    }
}
