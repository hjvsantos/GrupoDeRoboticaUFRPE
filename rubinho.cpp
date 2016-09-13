
int le = 7;
int ld = 5;
int lm = 6;

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
	int ded = abs(seRead - sdRead);
	int ddm = abs(sdRead - smRead);
	int dem = abs(seRead - smRead);
	int iso = 150;
	int alto = 600;
	Serial.println("-----------------");
	Serial.print("esquerda: ");
	Serial.println(seRead);
	Serial.print("meio: ");
	Serial.println(smRead);
	Serial.print("direita: ");
	Serial.println(sdRead);
        
	if(smRead >= seRead && smRead >=sdRead && dem >= iso && ddm >= iso)
	{
	  forward();
	  
	}
	else if(sdRead >= smRead && sdRead >= seRead && ddm >= iso && ded >= iso)
	{
	  right();
	  
	}
	else if(seRead >= smRead && seRead >=sdRead && ded >= iso && dem >= iso)
	{
	   left();
	  
	}
	else if(ded <= iso && ddm <= iso && dem <= iso)
	{
	  if(smRead >= alto)
	  {
		  forward();
	  }
	  else if(smRead < alto && sdRead >= alto)
	  {
		  backward();
		  right();
	  }
	  else if(smRead < alto && seRead >= alto)
	  {
		   backward();
		   left();
	  }
	}

 

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