#ifndef ROTARY_ENCODER_H_MARK
#define ROTARY_ENCODER_H_MARK 1



class RotaryEncoder
{
    public:
        // RotaryEncoder();
        void run();
        int position;
        // int CLK = 7;     // PIN
        // int DAT = 9;     // PIN
        // int BUTTON = 10;  // PIN
        int last_count = 0;
        // void RotateStateChanged(void);

    private:
        enum rotary_encoder_state
        {
            Idle,
            Turned,
            Pushed
         };
        rotary_encoder_state re_state;

        // const int interruptA = 0;      
        // const int interruptA = 7;   
        // const int interruptB = 1;  
        
        long unsigned int print_delay = 2000;   
        long unsigned int print_timer = 0;
 

        // enum direction_state{
        //     Backward,
        //     Forward
        // };
        // direction_state direction;


};

#endif