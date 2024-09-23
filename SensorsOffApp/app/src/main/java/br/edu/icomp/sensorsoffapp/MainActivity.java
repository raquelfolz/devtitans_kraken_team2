package br.edu.icomp.sensorsoffapp;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;
import devtitans.sysprop.SensorProperties;


public class MainActivity extends AppCompatActivity {

    private TextView textView;
    private Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        textView =     findViewById(R.id.textView);
        button = findViewById(R.id.button2);


        boolean enable = SensorProperties.smartlamp_enabled().orElse(false);
        if (enable) {
            textView.setText("Sensores Ligados");
            button.setText("Desligar");
        } else {
            textView.setText("Sensores Desligados");
            button.setText("Ligar");
        }
    }

    public void toggleButton(View view) {
        return;
    }
}
