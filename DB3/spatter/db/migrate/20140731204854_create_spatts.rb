class CreateSpatts < ActiveRecord::Migration
  def change
    create_table :spatts do |t|
      t.string :body
      t.belongs_to :user, index: true

      t.timestamps
    end
  end
end
