package bit.glennsp1.glennsp1_lab1;

import java.util.Random;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;


public class Lab1_Part1 extends Activity {

	TextView displayTextView;
	Button rndTextBtn;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab1__part1);
        
        displayTextView = (TextView)findViewById(R.id.displayText);
        rndTextBtn = (Button)findViewById(R.id.randTextBtn);
        rndTextBtn.setOnClickListener(onClick);
        
        rndTextBtn.performClick();
    }
    
    public void setDisplayText(String str) {
    	displayTextView.setText(str);
    }
    
    public String chooseDisplayText() {
    	Resources res = getResources();
    	String[] items = res.getStringArray(R.array.dogs);
    	
    	Random rGen = new Random();
    	return items[rGen.nextInt(items.length)];
    }

    OnClickListener onClick = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			String displayText = chooseDisplayText();
			setDisplayText(displayText);
		}
	};

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
