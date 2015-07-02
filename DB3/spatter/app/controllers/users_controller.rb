class UsersController < ApplicationController

  # GET /users
  # GET /users.json
  def index
    @users = User.all
	respond_to do |format|
		format.json { render json: @users.as_json(only: [:id, :name, :email, :blurb])}
	end
  end

  # GET /users/1
  # GET /users/1.json
  # Show method doesn't like using jbuilder template
  def show
    @user = User.find(params[:id])
	
	respond_to do |format|
		format.json { render json: @user.as_json(only: [:id, :name, :email, :blurb])}
	end
  end

  # POST /users
  # POST /users.json
  def create
    @user = User.new(user_params(params))
	
    if @user.save
      render json: @user, status: :created, location: @user
    else
      render json: @user.errors, status: :unprocessable_entity
    end
  end
  
  # DELETE /users/1
  # DELETE /users/1.json
  def destroy
    @user = User.find(params[:id])
    @user.destroy
    head :no_content
  end
  # PATCH/PUT /users/1
  # PATCH/PUT /users/1.json
  def update
    @user = User.find(params[:id])
	
    if @user.update(user_params(params[:user]))
      head :no_content
    else
      render json: @user.errors, status: :unprocessable_entity
    end
  end

  def show_follows
	@user = User.find(params[:id])
	render json: @user.follows
  end
  
  def show_followers
	@user = User.find(params[:id])
	render json: @user.followers
  end
  
  def add_follows
    @user = User.find(params[:id])
    @follows = User.find(params[:follows_id])

    if @user.follows << @follows
      head :no_content
    else
      render json: @user.errors, status: :unprocessable_entity
    end
  end
  
  def delete_follows
	@user = User.find(params[:id])
	@follows = User.find(params[:follows_id])
	
	if @user.follows.delete(@follows)
		head :no_content
    else
		render json: @user.errors, status: :unprocessable_entity
    end
  end
  
  def validate 
	@username = ActiveRecord::Base.connection.quote(params[:username])
	@password =  ActiveRecord::Base.connection.quote(params[:password])
	
	@user = User.find_by_sql("SELECT users.id FROM users WHERE users.name = #{@username} AND users.password = #{@password} ")

	respond_to do |format|
        format.json { render :json => @user }
	end
  end
  
  #get 'users/spatts/:id'
  def spatts
		if (params[:id][0].to_i > 0) 
			@spatts = Spatt.find_by_sql("SELECT spatts.body, spatts.user_id, spatts.id, spatts.created_at FROM spatts WHERE spatts.user_id = #{params[:id]} ORDER BY created_at DESC")
		else
			@spatts = Spatt.find_by_sql("SELECT spatts.body, spatts.user_id, spatts.id, spatts.created_at FROM spatts ORDER BY created_at DESC")
		end

		respond_to do |format|
			format.json { render json: @spatts.as_json(only: [:id, :body, :user_id, :created_at] )}
		end
  end
  

  #get 'users/spatts-feed/:id'
  def spatts_feed
	@feed = Spatt.find_by_sql("SELECT spatts.body, spatts.user_id, spatts.id, spatts.created_at FROM spatts JOIN follows ON follows.followed_id=spatts.user_id WHERE follows.follower_id=#{params[:id]} ORDER BY created_at DESC")
	render
  end


  
  private
  def user_params(params)
    logger.info "params:  #{params}"
    params.permit(:id, :name, :email, :password, :blurb)
  end
end
