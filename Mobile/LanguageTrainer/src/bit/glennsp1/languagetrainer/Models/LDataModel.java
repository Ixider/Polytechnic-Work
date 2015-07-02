package bit.glennsp1.languagetrainer.Models;

import java.io.Serializable;

public class LDataModel implements Serializable {
	
	public String Gender;
	public String Article;
	public String Noun;
	public String EnglishTranslation;
	public String ImageName;
	
	public LDataModel(String sGender, String sArticle, String sNoun, String sEnglishTranslation, String sImageName) {
		Gender = sGender;
		Article = sArticle;
		Noun = sNoun;
		EnglishTranslation = sEnglishTranslation;
		ImageName = sImageName;
	}
}
