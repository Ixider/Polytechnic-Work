package bit.glennsp1.lab4_1;

import android.app.Fragment;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView.FindListener;
import android.widget.ImageView;
import android.widget.TextView;

public class Content_DIsplay_Fragment extends Fragment {

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		
		View v = inflater.inflate(R.layout.content_display_fragment_layout, container, false);
		Bundle b = getArguments();
		
		loadTitle(b.getString("TITLE"), v);
		loadImage(b.getString("IMAGE_NAME"), v);
		
		return v;		
	}
	
	private void loadTitle(String title, View v) {
		TextView textView = (TextView)v.findViewById(R.id.title);
		textView.setText(title);
	}
	
	private void loadImage(String imageName, View v) {
		ImageView iv = (ImageView) v.findViewById(R.id.imageContent);
		iv.setImageDrawable(getDrawable(imageName));
	}
	
	private Drawable getDrawable(String imageName) {
		int id = getResources().getIdentifier(imageName, "drawable", getActivity().getPackageName());
		Drawable d = getResources().getDrawable(id);
		return d;
	}
	
	
}
