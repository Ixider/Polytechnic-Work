
	json.user @users do |user|
	  json.id = user.id
	  json.name user.name
	  json.password user.password
	  json.email user.email
	end
