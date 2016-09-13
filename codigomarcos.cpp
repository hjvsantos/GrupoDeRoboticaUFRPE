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
        
  
        
	smRead = analogRead(sm);
	seRead = analogRead(se);
	sdRead = analogRead(sd);

        
        if((smRead > seRead && smRead > sdRead && sdRead < meio && seRead < meio) || (smRead > meio && sdRead > meio && seRead > meio))
        {
          forward();
        }
        else if ((seRead > smRead && seRead > sdRead) || (seRead > sdRead && smRead > sdRead && smRead > meio))
        {
          left();
        }
//        else if((smRead > seRead && smRead > sdRead && sdRead < meio && seRead < meio) || (smRead > meio && sdRead > meio && seRead > meio))
//        {
//          forward();
//        }
        else if((sdRead > seRead && sdRead > smRead) || (smRead > seRead && sdRead > seRead && smRead > meio))
        {
          right();
        }
        
        else if(smRead < meio && sdRead < meio && seRead < meio)
        {
            backward();
        }  

       /* if(smRead >= preto && sdRead <= branco && seRead <= branco)
        {
           forward();
        }  
        
        else if(smRead <= branco && sdRead >= preto && seRead <= branco)
        {
           right();
        }
        
        else if(smRead <= branco && sdRead <= branco && seRead >= preto)
        {
           left();
        }
        
        else if(smRead >= preto && sdRead >= preto && seRead <= branco)
        {
           right();
        }
        
        else if(smRead >= preto && sdRead <= branco && seRead >= preto)
        {
           left();
        }
        
        else if(smRead >= preto && sdRead >= preto && seRead >= preto)
        {
           forward();
        } 
        
        else if(smRead <= branco && sdRead <= branco && seRead <= branco)
        {
            backward();
        }
        
       */ 
           
        
     /*   if((seRead > sdRead) && (seRead > smRead))
        {
          left();
          
        }else if((smRead > seRead) && (smRead > sdRead))
        {
       
          forward();
          
        }
        else if((sdRead > smRead) && (sdRead > seRead))
        {
          right();
          
        }
        
        */
        
	Serial.print("sm ");
        Serial.println(smRead);
	Serial.print("se"); 
        Serial.println(seRead);
	Serial.print("sd ");
        Serial.println(sdRead);
        Serial.println("");

  // put your main code here, to run repeatedly:
      //      digitalWrite(md1, HIGH);
	//digitalWrite(md2, LOW);
	//digitalWrite(me1, HIGH);
	//digitalWrite(me2, LOW);

        //delay(1000);
        
        //analogWrite(md1, 255);//RODA DA DIREITA
    
	//analogWrite(me1, 203);
	

	//delay(10000);
    

    //delay(2000);
    
       //  digitalWrite(md1, LOW);
	//digitalWrite(md2, HIGH);
	//digitalWrite(me1, LOW);
	//digitalWrite(me2, HIGH);
        //delay(1000);
        
         //digitalWrite(md1, LOW);
        // digitalWrite(md2, HIGH);
	//analogWrite(md2, 255);
	//digitalWrite(me1, LOW);
   //     digitalWrite(me2, HIGH);
	//analogWrite(me2, 203);

   // delay(10000);
    
    

   // delay(2000);


}


void forward()
{
	digitalWrite(md1, HIGH);
	digitalWrite(md2, LOW);
    digitalWrite(me1, HIGH);
    digitalWrite(me2, LOW);

}

void left()
{
	digitalWrite(md1, LOW);
	digitalWrite(md2, HIGH);
    digitalWrite(me1, HIGH);
    digitalWrite(me2, LOW);

}

void right()
{
	digitalWrite(md1, HIGH);
	digitalWrite(md2, LOW);
    digitalWrite(me1, LOW);
    digitalWrite(me2, HIGH);
}

void backward()
{
  	digitalWrite(md1, LOW);
	digitalWrite(md2, HIGH);
    digitalWrite(me1, LOW);
    digitalWrite(me2, HIGH);
}  

void off()
{
	digitalWrite(md1, LOW);
	digitalWrite(md2, LOW);
	digitalWrite(me1, LOW);
	digitalWrite(me2, LOW);
}

