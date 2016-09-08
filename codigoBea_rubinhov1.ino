 

int le = 7;
int lm = 6;
int ld = 5;

int md2 = 10;
int md1 = 9;
int me1 = 11;
int me2 = 3;

int sm = A3;
int sd = A2;
int se = A1;

int smRead;
int seRead;
int sdRead;

//int preto = 600;
//int branco = 500; 
int meio = 511;


void setup() {
  // put your setup code here, to run once:
	pinMode(md1, OUTPUT);
	pinMode(md2, OUTPUT);
	pinMode(me1, OUTPUT);
	pinMode(me2, OUTPUT);
        pinMode(le, OUTPUT);
        pinMode(lm, OUTPUT);
        pinMode(ld, OUTPUT);
	Serial.begin(9600);
        digitalWrite(le, HIGH);
        digitalWrite(ld, HIGH);
        digitalWrite(lm, HIGH);

}

void loop() {
       
        
        if(smRead >= seRead && smRead >=sdRead)
        {
          forward();
          
        }
        else if(sdRead >= smRead && sdRead >= seRead)
        {
          right();
          
        }
        else if(seRead >= smRead && seRead >=sdRead)
        {
           left();
          
        }
 

}


void forward()
{
	digitalWrite(md1, HIGH);
	digitalWrite(md2, LOW);
    digitalWrite(me1, HIGH);
    digitalWrite(me2, LOW);
    
    delay(1000);

}

void left()
{
	digitalWrite(md1, LOW);
	digitalWrite(md2, HIGH);
    digitalWrite(me1, HIGH);
    digitalWrite(me2, LOW);
    
    delay(1000);

}

void right()
{
	digitalWrite(md1, HIGH);
	digitalWrite(md2, LOW);
    digitalWrite(me1, LOW);
    digitalWrite(me2, HIGH);
    
    delay(1000);
}

void backward()
{
      digitalWrite(md1, LOW);
      digitalWrite(md2, HIGH);
      digitalWrite(me1, LOW);
      digitalWrite(me2, HIGH);
      
      delay(1000);
}  

void off()
{
	digitalWrite(md1, LOW);
	digitalWrite(md2, LOW);
	digitalWrite(me1, LOW);
	digitalWrite(me2, LOW);
}

