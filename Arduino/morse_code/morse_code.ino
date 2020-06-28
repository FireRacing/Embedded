int pin = 13;
void setup() {
  pinMode(pin, OUTPUT);
}
void dot()
{
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
}
void dash()
{
  digitalWrite(pin,HIGH);
  delay(1500);
  digitalWrite(pin,LOW);
}
void loop() {
  int i,j;
  String s = "Hello";
  for(i = 0 ; i < s.length() ; i++)
  {
    if(s[i] == ' ')
    {
      for(j = 0; j < 7 ; i++)
      {
        delay(250);
        dot();
      }
    }
    else{
      if(s[i] == 'a' || s[i] == 'A')
      {
        dot();
        delay(250);
        dash();
      }
      else if(s[i] == 'b' || s[i] == 'B')
      {
        dash();
        for(j= 0; j < 3; j++)
        {
          delay(250);
          dot();
        }
      }
      else if(s[i] == 'c' || s[i] == 'C')
      {
        dash();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == 'd' || s[i] == 'D')
      {
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == 'e' || s[i] == 'E')
        dot();
      else if(s[i] == 'f' || s[i] == 'F')
      {
        dot();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == 'g' || s[i] == 'G')
      {
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == 'h' || s[i] == 'H')
      {
        dot();
        for(j = 0; j < 3; j++)
        {
          delay(250);
          dot();
        }
      }
      else if(s[i] == 'i' || s[i] == 'I')
      {
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == 'j' || s[i] == 'J')
      {
        dot();
        for(j = 0;j < 3; j++)
        {
          delay(250);
          dash();
        }
      }
      else if(s[i] == 'k' || s[i] == 'K')
      {
        dash();
        delay(250);
        dot();
        delay(250);
        dash();
      }
      else if(s[i] == 'l' || s[i] == 'L')
      {
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == 'm' || s[i] == 'M')
      {
        dash();
        delay(250);
        dash();
      }
      else if(s[i] == 'n' || s[i] == 'N')
      {
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == 'o' || s[i] == 'O')
      {
        dash();
        delay(250);
        dash();
        delay(250);
        dash();
      }
      else if(s[i] == 'p' || s[i] == 'P')
      {
        dot();
        delay(250);
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == 'q' || s[i] == 'Q')
      {
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dash();
      }
      else if(s[i] == 'r' || s[i] == 'R')
      {
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == 's' || s[i] == 'S')
      {
        dot();
        delay(250);
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == 't' || s[i] == 'T')
      {
        dash();
      }
      else if(s[i] == 'u' || s[i] == 'U')
      {
        dot();
        delay(250);
        dot();
        delay(250);
        dash();
      }
      else if(s[i] == 'v' || s[i] == 'V')
      {
        dot();
        delay(250);
        dot();
        delay(250);
        dot();
        delay(250);
        dash();
      }
      else if(s[i] == 'w' || s[i] == 'W')
      {
        dot();
        delay(250);
        dash();
        delay(250);
        dash();
      }
      else if(s[i] == 'x' || s[i] == 'X')
      {
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
        delay(250);
        dash();
      }
      else if(s[i] == 'y' || s[i] == 'Y')
      {
        dash();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dash();
      }
      else if(s[i] == 'z' || s[i] == 'Z')
      {
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == '.')
      {
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dash();
      }
      else if(s[i] == ',')
      {
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dash();
      }
      else if(s[i] == '?')
      {
        dot();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == '/')
      {
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == '@')
      {
        dot();
        delay(250);
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dash();
        delay(250);
        dot();
      }
      else if(s[i] == '1')
      {
        dot();
        delay(250);
        for(j = 0; j < 4; j++)
        {
          dash();
          delay(250);
        }
      }
      else if(s[i] == '2')
      {
        dot();
        delay(250);
        dot();
        delay(250);
        for(j = 0; j < 3; j++)
        {
          dash();
          delay(250);
        }
      }
      else if(s[i] == '3')
      {
        for(j = 0; j < 3; j++)
        {
          dot();
          delay(250);
        }
        dash();
        delay(250);
        dash();
      }
      else if(s[i] == '4')
      {
        for(j = 0; j < 4; j++)
        {
          dot();
          delay(250);
        }
        dash();
      }
      else if(s[i] == '5')
      {
        for(j = 0; i < 4; i++)
        {
          dot();
          delay(250);
        }
        dot();
      }
      else if(s[i] == '6')
      {
        dash();
        delay(250);
        for(j = 0; j < 3; j++)
        {
          dot();
          delay(250);
        }
        dot();
      }
      else if(s[i] == '7')
      {
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == '8')
      {
        dash();
        delay(250);
        dash();
        delay(250);
        dash();
        delay(250);
        dot();
        delay(250);
        dot();
      }
      else if(s[i] == '9')
      {
        for(j = 0; j < 4; j++)
        {
          dash();
          delay(250);
        }
        dot();
      }
      else if(s[i] == '0')
      {
        for(j = 0; j < 4; j++)
        {
          dash();
          delay(250);
        }
        dash();
      }
    }
    delay(250);
  }
  digitalWrite(pin,LOW);
  delay(5000);
}
