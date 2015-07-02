package bit.glennsp1.languagetrainer;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;


import android.os.Bundle;
import android.support.v4.app.DialogFragment;



public class ConfirmationDialog extends DialogFragment{
	
	String str;
	ConfirmationDialogListener mListener;
	
	public ConfirmationDialog(String str) { this.str = str; }
	public String getAnswer() { return str; }
	
	public interface ConfirmationDialogListener {
	    public void onDialogPositiveClick(DialogFragment dialog);
	    public void onDialogNegativeClick(DialogFragment dialog);
	}
	
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        // Use the Builder class for convenient dialog construction
        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setMessage("Do you want to procced with your answer, "+ str +"?")
               .setPositiveButton("Accept", new DialogInterface.OnClickListener() {   
                   public void onClick(DialogInterface dialog, int id) { 
                	   mListener.onDialogPositiveClick(ConfirmationDialog.this);
                   }
               })
               .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                   public void onClick(DialogInterface dialog, int id) {
                	   mListener.onDialogNegativeClick(ConfirmationDialog.this);
                   }
               });
        // Create the AlertDialog object and return it
        return builder.create();
    }// End onCreateDialog

	@Override
	public void onAttach(Activity activity) {
		super.onAttach(activity);
		try {
            // Instantiate the NoticeDialogListener so we can send events to the host
            mListener = (ConfirmationDialogListener) activity;
        } catch (ClassCastException e) {
            // The activity doesn't implement the interface, throw exception
            throw new ClassCastException(activity.toString()
                    + " must implement ConfirmationDialogListener");
        }
    }// End onAttach
}
