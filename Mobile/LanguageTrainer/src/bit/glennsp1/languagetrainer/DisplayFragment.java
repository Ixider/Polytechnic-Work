package bit.glennsp1.languagetrainer;

import bit.glennsp1.languagetrainer.Models.LDataModel;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

public class DisplayFragment extends Fragment {

	LDataModel currModel;
	@Override
	public View onCreateView(LayoutInflater inflater,
			@Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		View v = inflater.inflate(R.layout.fragment_display, container, false);
		
		currModel = (LDataModel)getArguments().getSerializable("Model");
		
		TextView noun = (TextView)v.findViewById(R.id.nounDisplay);
		noun.setText(currModel.Noun);
		
		TextView english = (TextView)v.findViewById(R.id.englishTranslation);
		english.setText(currModel.EnglishTranslation);
		
		ImageView image = (ImageView)v.findViewById(R.id.imageView1);
		
		int id = getResources().getIdentifier(currModel.ImageName, "drawable", getActivity().getPackageName());
		Drawable d = getResources().getDrawable(id);
		
		image.setImageDrawable(d);
		
		return v;
	}
	
	public void computeAwnser(String str) {	
		displayFeedBack(str.equals(currModel.Article), str);
	}
	
	public void displayFeedBack(boolean b, String str) {
		ResultDialog rd;
		String message = "You answered: " +str+"\n\n" 
						+ "English: " + currModel.EnglishTranslation + "\n"
						+ "Noun: " + currModel.Noun + "\n"
						+ "Article: " + currModel.Article + "\n"
						+ "Gender: " + currModel.Gender + "\n";	
		
		if(b) {
			rd = new ResultDialog("Correct", message);
			((LessonDisplay)getActivity()).incrementStreak();
			((LessonDisplay)getActivity()).incrementCorrectCount();
		} else {
			rd = new ResultDialog("Incorrect", message);
			((LessonDisplay)getActivity()).resetStreak();
		}
		
		rd.show(getActivity().getSupportFragmentManager(), "Dialog");
	}
}
