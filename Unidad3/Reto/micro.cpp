void setup() {
    Serial.begin(115200);
}

void loop() {

    static float numx1 = 1.5787; //3fca12d7
    static uint8_t arrx1[4] = {0};

    static float numx2 = 3.5787; //4065096c
    static uint8_t arrx2[4] = {0};
    //static float numy1 = 1.5;
    //static float numy2 = 3.5;
    //static float numz1 = 1.5;
    //static float numz2 = 3.5;
    if(Serial.available())
    {
      char input = Serial.read();
        if(input == '1')
        {
            memcpy(arrx1,(uint8_t *)&numx1,4);
            for(int8_t i = 3; i >= 0; i--)
            {
              Serial.write(arrx1[i]);
            }
        }
        if (input == '2')
        {
            memcpy(arrx2,(uint8_t *)&numx2,4);
            for(int8_t i = 3; i >= 0; i--)
            {
              Serial.write(arrx2[i]);
            }
        }
    }
    }

