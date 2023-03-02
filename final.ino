float c,d,Rt,e,g;
float a[]={0x7,0xb,0xd,0xe};
float b[]={0x3f,0x6,0x56,0x4f,0x66,0x6d,0x7c,0x7,0x7f,0x67,0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xe7};
int f[4];
unsigned long t1,t2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
DDRB=0xFF;
DDRC=0xFF;
c=analogRead(A1);

d=(c/1023)*5;
Rt=d*5/(5-d);
g=1/298.15+log(Rt/5)/3600;
e=1/g-273.15+0.5;
Serial.println(e);

t1=millis();
f[0]=e/10;
f[1]=(e-f[0]*10)/1;
f[2]=((e*10)-f[0]*100-f[1]*10)/1;
f[3]=((e*100)-f[0]*1000-f[1]*100-f[2]*10)/1;

do{

 PORTC=a[0];
 PORTB=b[f[0]];
 delay(1);

 PORTC=a[1];
 PORTB=b[f[1]+10];
 delay(1);

 PORTC=a[2];
 PORTB=b[f[2]];
 delay(1);

 PORTC=a[3];
 PORTB=b[f[3]];
 delay(1);

 PORTA=0;
 if(e>=30)
 digitalWrite(22,HIGH);
 else
 digitalWrite(23,HIGH);

 t2=millis();
}while((t2-t1)<5000);
}
