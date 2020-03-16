#include <Arduino.h>
#include <Wire.h>

/***************************************************************
 *
 * Print auf verschiedene Kanäle
 *
 * (Wire/Serial/WiFi/LCD/GSM etc.
 *
 * meistens mit einer Tmplate -Funktion
 *
 * *************************************************************/




#define mitKlassecl

/** some Test Stuff*/
class cla{
public:
    cla(int a) {}
    cla(){}

    size_t foo=2;
    void cla_func(){}
};
cla cc(5);
void f(){
    cc.cla_func();

}

//Boost any
namespace boost {
    class bad_any_cast;
    class any;
    template<typename T> T any_cast(any &);
    template<typename T> T any_cast(const any &);
    template<typename ValueType> const ValueType * any_cast(const any *);
    template<typename ValueType> ValueType * any_cast(any *);
}

/************************
 * HasPrint Struct
 *
 * Stuktur mit Kanälen
 *
 * **********************/
static struct stru {
    HardwareSerial& ser =Serial;  //ser ist eine Referenz
    TwoWire& wir= Wire;
} hasprint;

/**********************************
 * Print to mit Template Funktion
 * ********************************/
template <class to, typename s>
void print_to( to &to1, s string) {
    to1.print(string);
}


/*********************************
 *
 * MY Output Class cl
 *
 * """"""""""""""""""""""""""""""*/
/* Class Definition*/
class cl
{
public:
    cl(){};
    /* Member Funktion definieren*/
    /** Template */
    template <class OUTPUT_CHANNEL>
    void out(OUTPUT_CHANNEL &outputChannel) {
        outputChannel.print(" nochmals ");
    }
};
/* Implementation der Klasse*/
cl my_cl;


/************************************************************
 *   Out Put Template mit Static Text und zusätzl. Parameter
 * **********************************************************/
template <class OUTPUT_CHANNEL, typename tname>
void Print_to (OUTPUT_CHANNEL &output_Chanel,tname tname1)
{
    static int n=0;
    tname x = tname1;

    dynamic_cast<OUTPUT_CHANNEL&>(output_Chanel).print ("sowas");
    output_Chanel.print("ficken bis der Artz kommt ");
    output_Chanel.print(n++);
}

/***********************************
 * Setup
 * **********************************/
void setup() {
    Serial.begin(9600);
    Wire.begin();
    Serial.println("Mother fucker");
}

/**********************************
 * Loop
 * ********************************/
void loop() {

    /** Einige Print Versuche*/

    Serial.print("Mother Fucker"); // normal

    Print_to(Serial,5);  // mit zus. Parameter

    my_cl.out(Serial);   //Mit Klasse

    print_to(Serial,"ganz neu");  //String ausgeben

    print_to(hasprint.ser,"na sowas"); //mit Struct hasprint


    dynamic_cast<HardwareSerial*>(&Serial)->println("fcuk"); //dynamic Casting (nicht nötig!)

    HardwareSerial *a= &Serial;  //Pointer
    a->print("mother");

    delay(100);
}