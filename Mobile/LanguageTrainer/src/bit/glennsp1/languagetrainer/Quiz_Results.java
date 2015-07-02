package bit.glennsp1.languagetrainer;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class Quiz_Results extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lesson__results);
		
		TextView tv1 = (TextView)findViewById(R.id.ProgLabel);
		Intent b = getIntent();
		
		int str1 = b.getIntExtra("CorrectCount", 0);
		tv1.setText("You got " + String.valueOf(str1) + " correct");
		
		int str2 = b.getIntExtra("Streak", 0);
		TextView tv2 = (TextView)findViewById(R.id.strLabel);
		tv2.setText("Your highest Streak was: " + String.valueOf(str2));
		
	}
}
