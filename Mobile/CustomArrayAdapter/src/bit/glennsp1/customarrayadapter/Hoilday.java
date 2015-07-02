package bit.glennsp1.customarrayadapter;

import android.graphics.drawable.Drawable;

public class Hoilday {

	public String name;
	public String month;
	public String day;
	public Drawable icon;
	
	public Hoilday(String name, String month, String day, Drawable icon){
		this.name = name;
		this.month = month;
		this.day = day;
		this.icon = icon;
	}

	@Override
	public String toString() {
		return name + " is on the " + day + " of " + month;
	}
}
