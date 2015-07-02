package bit.glennsp1.customarrayadapter;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.Context;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;

public class MainActivity extends Activity {

	List<Hoilday> hoildays;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        configureUI();
    }
    
    
    
    private void configureUI() {
    	Resources res = getResources();
    	
    	Drawable easterImage =  res.getDrawable(R.drawable.easter);
    	Drawable mothersDay = res.getDrawable(R.drawable.mothersday);
    	Drawable haloween = res.getDrawable(R.drawable.haloween);
    	
    	hoildays = new ArrayList<Hoilday>();
    	
    	hoildays.add(new Hoilday("Easter", "April", "5th", easterImage));
    	hoildays.add(new Hoilday("Mothers Day", "May", "10th", mothersDay));
    	hoildays.add(new Hoilday("Haloween", "October", "31st", haloween));	
    }
    
    public class HoildayAdapter extends ArrayAdapter<Hoilday> {

		public HoildayAdapter(Context context, int resource) {
			super(context, resource);
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			// TODO Auto-generated method stub
			return super.getView(position, convertView, parent);
		}
    	
		
    }
}
