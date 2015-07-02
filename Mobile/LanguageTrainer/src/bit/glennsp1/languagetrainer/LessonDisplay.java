package bit.glennsp1.languagetrainer;

import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;
import org.xmlpull.v1.XmlPullParserException;

import bit.glennsp1.languagetrainer.ConfirmationDialog.ConfirmationDialogListener;
import bit.glennsp1.languagetrainer.ResultDialog.ResultDialogListener;
import bit.glennsp1.languagetrainer.Models.LDataModel;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;


public class LessonDisplay extends FragmentActivity implements ConfirmationDialogListener, ResultDialogListener {

	private int questionIndex;
	private int streakCount;
	
	private int highestStreak;
	private int correctCount;
	
	private ArrayList<LDataModel> lessonData;
	DisplayFragment df;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lesson_display);
		
		questionIndex = 0;
		streakCount = 0;
		
		highestStreak = 0;
		correctCount = 0;
		
		df = null;
		
		int i = getIntent().getExtras().getInt("LessonNumber");
        lessonData = retriveData(i);
        
        if(lessonData.size() != 0)
        	startFragment(lessonData.get(questionIndex));
       
        configureUI();

	}// End onCreate
	
	private void configureUI() {
        Button answerButton1 = (Button)findViewById(R.id.answerBtnLeft);
        answerButton1.setOnClickListener(onButtonClick);
        Button answerButton2 = (Button)findViewById(R.id.answerBtnCenter);
        answerButton2.setOnClickListener(onButtonClick);
        Button answerButton3 = (Button)findViewById(R.id.answerBtnRight);
        answerButton3.setOnClickListener(onButtonClick);
        
        ProgressBar progressBar = (ProgressBar) findViewById(R.id.progressBar1);
        progressBar.setMax(lessonData.size());
       
        setProgress();
        setStreak();
	}// End congigureUI
	
	// Retrieve collection of information for the displayFragment
	private ArrayList<LDataModel> retriveData(int lessonNumber) {	
        DataFactory factory = new DataFactory(getAssets()); 
        ArrayList<LDataModel> data = new ArrayList<LDataModel>();
        
        try {
			 data = (ArrayList<LDataModel>) factory.getData(lessonNumber + 1);
		} catch (IOException e) {
			e.printStackTrace();
		} catch (XmlPullParserException e) {
			e.printStackTrace();
		}
        
        return data;
	}// End retriveData
	
	OnClickListener onButtonClick = new OnClickListener() {
	
		@Override
		public void onClick(View v) {
			Button b = (Button)v;
			String buttonText = (String)b.getText();
			
			ConfirmationDialog dialog = new ConfirmationDialog(buttonText);
			dialog.show(getSupportFragmentManager(), "Dialog");
		}
	}; // End onButtonClick
	
	public void changeItem() {
		questionIndex++;
		if(questionIndex < lessonData.size()) {
			setProgress();
			startFragment(lessonData.get(questionIndex));	
		}
	}// End changeItem
	
	public void incrementCorrectCount() {
		correctCount++;
	}// End incrementCorrectCount
	
	public void incrementStreak(){
		streakCount++;
		setStreak();
	}// End incrementStreak
	
	public void resetStreak() {
		if(streakCount > highestStreak) 
			highestStreak = streakCount;
		streakCount = 0;
		setStreak();
	}// End resetStreak
	
	private void startQuizResults() {
		Intent i = new Intent(getBaseContext(), Quiz_Results.class);
		i.putExtra("CorrectCount", correctCount);
		i.putExtra("Streak", highestStreak);
		
		startActivity(i);
		finish();
	}// End startQuizResults
	
	// give data to fragment to be displayed in the frame layout.
	private void startFragment(LDataModel model) {
		FragmentManager fragmentManager = getSupportFragmentManager();
		FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
		
		Bundle bundle = new Bundle();
		bundle.putSerializable("Model", (Serializable) model);
		
		df = new DisplayFragment();
		df.setArguments(bundle);
		
		fragmentTransaction.setCustomAnimations(R.anim.right_in, R.anim.left_out);		
		fragmentTransaction.replace(R.id.fragmentDisplay, df);
		fragmentTransaction.commit();
		
	}// End startFragment

	private void setProgress() {
        TextView progressTextView = (TextView)findViewById(R.id.progressLable);
        progressTextView.setText("Q: " + String.valueOf(questionIndex + 1) + "/" + String.valueOf(lessonData.size()));
        
        ProgressBar progressBar = (ProgressBar) findViewById(R.id.progressBar1);
        progressBar.incrementProgressBy(1);
	}// End setProgress
	
	private void setStreak() {
        TextView streakTextView = (TextView)findViewById(R.id.streakCounter);
        streakTextView.setText("Streak: " + String.valueOf(streakCount));
	}// End setStreak
	
	
	// Confirmation and result dialog overrides
	@Override
	public void onDialogPositiveClick(DialogFragment dialog) {
		df.computeAwnser(((ConfirmationDialog) dialog).getAnswer());
	}// End onDialogPositiveClick

	@Override
	public void onDialogNegativeClick(DialogFragment dialog) {
		dialog.dismiss();
	}//End onDialogNegativeClick 

	@Override
	public void onResultDialogPositiveClick(DialogFragment dialog) {
		if(questionIndex >= lessonData.size()) {
			startQuizResults();
		}	
		
		changeItem();
	} // End onResultDialogPositiveClick
	
}// End Activity


