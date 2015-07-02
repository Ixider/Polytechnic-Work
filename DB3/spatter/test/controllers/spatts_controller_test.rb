require 'test_helper'

class SpattsControllerTest < ActionController::TestCase
  setup do
    @spatt = spatts(:one)
  end

  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:spatts)
  end

  test "should create spatt" do
    assert_difference('Spatt.count') do
      post :create, spatt: { body: @spatt.body, user_id: @spatt.user_id }
    end

    assert_response 201
  end

  test "should show spatt" do
    get :show, id: @spatt
    assert_response :success
  end

  test "should update spatt" do
    put :update, id: @spatt, spatt: { body: @spatt.body, user_id: @spatt.user_id }
    assert_response 204
  end

  test "should destroy spatt" do
    assert_difference('Spatt.count', -1) do
      delete :destroy, id: @spatt
    end

    assert_response 204
  end
end
