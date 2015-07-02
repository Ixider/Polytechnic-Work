package bit.glennsp1.glennsp1_lab1;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class Lab1_Part2 extends Activity {
	
	TextView displayTextView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lab1__part2);
		
		displayTextView = (TextView)findViewById(R.id.datesTextView);
		displayDates();
	}

	public void displayDates() {
		Resources res = getResources();
		int[] dates = res.getIntArray(R.array.febDates);
		
		for(int i : dates) {
			displayTextView.append(Integer.toString(i)+ " ");
		}
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.lab1__part2, menu);
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
