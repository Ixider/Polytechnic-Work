package bit.glennsp1.glennsp1_lab2;

import com.example.glennsp1_lab2.R;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.util.Log;

public class MainPager extends FragmentActivity {

	static final int NUM_PAGES = 3;
	
	private ViewPager viewPager;
	private PagerAdapter pageAdapter;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_pager);
        
        
        viewPager = (ViewPager)findViewById(R.id.pager);
        pageAdapter = new ScreenPageAdapter(getSupportFragmentManager());
        viewPager.setAdapter(pageAdapter);
        
    } // End OnCreate
    
} // End Fragment Activity

class ScreenPageAdapter extends FragmentPagerAdapter {

	public ScreenPageAdapter(FragmentManager fm) {
		super(fm);
	} // End Constructor

	@Override
	public Fragment getItem(int position) {
		
		Fragment fragment = null;
		
		switch(position) {
			case 0:
				fragment =  new Task1();
				break;
			case 1:
				fragment = new Task2();
				break;
			case 2:
				fragment = new Task3();
				break;
			default:
				Log.v("Error", "Fragment selection switch has defaulted");
				break;
			
		} // End Switch
		
		return fragment;
	} // End getItem

	@Override
	public int getCount() {
		return MainPager.NUM_PAGES;
	} // End getCount
	
	@Override
	public CharSequence getPageTitle(int pos) {
		return "Task " + (pos + 1);
	} // End getPageTitle
}