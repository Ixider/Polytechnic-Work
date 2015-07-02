class SpattsController < ApplicationController
  # GET /spatts
  # GET /spatts.json
  def index
    @spatts = Spatt.all

    render json: @spatts
  end

  # GET /spatts/1
  # GET /spatts/1.json
  def show
    @spatt = Spatt.find(params[:id])

    render json: @spatt
  end

  # POST /spatts
  # POST /spatts.json
  def create
    @spatt = Spatt.new(spatt_params(params[:spatt]))

    if @spatt.save
      render json: @spatt, status: :created, location: @spatt
    else
      render json: @spatt.errors, status: :unprocessable_entity
    end
  end


  # DELETE /spatts/1
  # DELETE /spatts/1.json
  def destroy
    @spatt = Spatt.find(params[:id])
    @spatt.destroy

    head :no_content
  end
  
private 
	def spatt_params(params)
		params.permit(:body, :user_id)
	end
	

end
