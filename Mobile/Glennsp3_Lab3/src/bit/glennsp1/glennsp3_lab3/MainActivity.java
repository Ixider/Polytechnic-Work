package bit.glennsp1.glennsp3_lab3;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;


public class MainActivity extends Activity implements MyAlertDialog.DialogListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        configureUI();
    }// End onCreate
    
    private void configureUI() {
        Spinner monthsSpinner = (Spinner)findViewById(R.id.enrollmentDateSpinner);
        Resources res = getResources();
       
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_dropdown_item, res.getStringArray(R.array.start_months));
        monthsSpinner.setAdapter(adapter);
                                
        Button enrolButton = (Button)findViewById(R.id.enrolButton);
        enrolButton.setOnClickListener(onClick);
    }//End configureUI
    
    OnClickListener onClick = new OnClickListener() {
		@Override
		public void onClick(View v) {
			String instrument = getInstrument();
			String startDate = getStartDate();
			
			MyAlertDialog dialog = new MyAlertDialog();
			dialog.setTitle("Are you sure you want to enrol for " + instrument + " lessons?");
			dialog.setMessage("Start Date: " + startDate);
			
			dialog.show(getFragmentManager(), "");
		}
	};// End onClick
	
	private void setConfirmationText(String instrument, String startDate) {
		TextView confirmationTextLable = (TextView)findViewById(R.id.confirmation_lable);
		confirmationTextLable.setText("You are enrolled for " + instrument + " lessons, starting in " + startDate);
	}// End setConfirmationText
	
	private String getStartDate() {
		Spinner startDateSpinner = (Spinner)findViewById(R.id.enrollmentDateSpinner);
		return startDateSpinner.getSelectedItem().toString();
	}// End getStartDate

	private String getInstrument() {
		RadioGroup radioGroup = (RadioGroup)findViewById(R.id.radioGroup1);
		RadioButton radioButton = (RadioButton)findViewById(radioGroup.getCheckedRadioButtonId());		
		return (String)radioButton.getText();
	}// End getInstrument
	
	// Dialog overrides
	@Override
	public void onDialogPositiveClick(android.app.DialogFragment dialog) {
		setConfirmationText(getInstrument(), getStartDate());
	}

	@Override
	public void onDialogNegativeClick(android.app.DialogFragment dialog) {
		setConfirmationText("Nothing", "Never");
		dialog.dismiss();
	}
}
