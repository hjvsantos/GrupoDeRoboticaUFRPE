int le = 7;
int lm = 6;
int ld = 5;
int lsc = 4;

int md2 = 10;
int md1 = 9;
int me1 = 11;
int me2 = 3;

int sm = A3;
int sd = A2;
int se = A1;
int spc = 2;

int smRead;
int seRead;
int sdRead;
int spcRead;

int meio = 511;
int contador = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sm, INPUT);
  pinMode(sd, INPUT);
  pinMode(se, INPUT);
  pinMode(spc, INPUT);
  pinMode(md1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(me1, OUTPUT);
  pinMode(me2, OUTPUT);
  pinMode(le, OUTPUT);
  pinMode(lm, OUTPUT);
  pinMode(ld, OUTPUT);
  pinMode(lsc, OUTPUT);
  Serial.begin(9600);
  digitalWrite(le, HIGH);
  digitalWrite(ld, HIGH);
  digitalWrite(lm, HIGH);
  digitalWrite(lsc, HIGH);
}

void loop() {
        
  
        
  smRead = analogRead(sm);
  seRead = analogRead(se);
  sdRead = analogRead(sd);
  spcRead = digitalRead(spc);
    if(contador < 2)
    {
          if((smRead > seRead && smRead > sdRead && sdRead < meio && seRead < meio) || (smRead > meio && sdRead > meio && seRead > meio))
          {
            forward();
          }
          else if ((seRead > smRead && seRead > sdRead) || (seRead > sdRead && smRead > sdRead && smRead > meio))
          {
            left();
          }
          else if((sdRead > seRead && sdRead > smRead) || (smRead > seRead && sdRead > seRead && smRead > meio))
          {
            right();
          }
          
          else if(smRead < meio && sdRead < meio && seRead < meio)
          {
              backward();
          }  

          // quando todos os sensores estiverem no preto, levantar flag.
          //depois fazer uma flag pra cruzamento
          //quando o meio e o pc estiverem pretos ele and normal e conta.
    }
    else
    {
      off();   
    }
  /*Serial.print("sm ");
  Serial.println(smRead);
  Serial.print("se"); 
  Serial.println(seRead);
  Serial.print("sd ");
  Serial.println(sdRead);
  Serial.println("");
  Serial.println("spc");
  Serial.print(spcRead);
  Serial.println("");*/

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


