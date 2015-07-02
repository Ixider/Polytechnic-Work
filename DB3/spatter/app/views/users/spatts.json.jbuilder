json.spatts @spatts do |spatt|
  json.posted_by spatt.user.name
  json.body spatt.body
  json.created_at spatt.created_at
end